// BINARY SEARCH TREE IMPLEMENTATION IN C++

#include<bits/stdc++.h>
using namespace std;

// BST Class
class BST{
    // Node Class
    class Node{
    public:    
        int data;//data of Node
        Node* left; //left pointer
        Node* right;// right pointer

        Node() // Default Constructer
        {
            left=NULL;
            right=NULL;
        }
        Node(int x) // Parameterized Constructor
        {
            data=x;
            left=NULL;
            right=NULL;
        }
        ~Node() // Destructor
        {
            cout << "NODE DESTROYED!!!\n";
        }
    };
    // PRIVATE
    // Member Functions
    Node* insertion(Node*,int);
    Node* deletion(Node*,int);
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
    Node* findMin(Node*);
    Node* findMax(Node*);
    bool isEmpty();
    // Data Members
    unordered_map<int,int>m;
    Node* head=NULL;
public:
    // PUBLIC
    BST() // Default Constructor
    {
        cout << "\n\n..............Welcome to BST Implementation..............\n\n";
    }
    ~BST() // Destructor
    {
        cout << "\n\n..............THE END!!!!..............\n\n";
    }
    // Member Functions
    void insert(int);
    void deleteNode(int);
    void Traversals();
    void Top();
};

// Wrapper Function for Insertion Opertaion..
void BST::insert(int val)
{
    // Checks for Duplicate Element..
    if(m.find(val)==m.end())
    {
        head=insertion(head,val);
        // Insert into the Map.
        m[val]=1;
        return;
    }
    cout << "Element Already Exist in BST!!!!!\n";
}

// Insert Function to Insert Node in the BST..
BST::Node* BST::insertion(Node* root,int val)
{
    if(root==NULL)
        root=new Node(val);
    else if(root->data<val)
        root->right=insertion(root->right,val);
    else
        root->left=insertion(root->left,val);
    return root;    
}

// Wrapper Function for Deletion Opertaion..
void BST:: deleteNode(int val)
{
    if(!isEmpty())
    {
        // Checks if Node exist in BST
        if(m.find(val)==m.end())
            cout << "Node doesn't EXIST!!!\n";
        else
        {
            head=deletion(head,val);
            // Then erase it from the Map as well.
            m.erase(val);
        }    
    }    
}

// Delete Function to Delete node from the BST..
BST::Node* BST::deletion(Node* root,int val)
{
    if(root->data>val) // if root->data is greater than value then goto left
    root->left=deletion(root->left,val); 
    else if(root->data<val) // if root->data is lesser than value then goto right
    root->right=deletion(root->right,val);
    else
    {
        // Case-1 (0- Child)
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            root=NULL;
            return root;
        }
        // Case-1 (1- Child(RIGHT))
        else if (root->left==NULL) 
        {
            Node* temp=root;
            root=root->right;
            delete(temp);
            return root;
        }
        // Case-1 (1- Child(LEFT))
        else if (root->right==NULL) 
        {
            Node* temp=root;
            root=root->left;
            delete(temp);
            return root;
        }
        // Case-1 (2- Child)
        else
        {
            cout << "DELETE Node according to--> \n";
            cout << "1- INORDER PREDECESSOR\n";
            cout << "2- INORDER SUCCESSOR\n";
            int x;
            cout << "Enter--> ";
            cin >> x;
            while(x<1 || x>2)
            {
                cout << "Enter a Valid Input...\n";
                cout << "Enter--> ";
                cin >> x;
            } 
            Node* temp=NULL;
            if(x==1) // Using INORDER PREDECESSOR
            {
                temp=findMax(root->left);
                root->data=temp->data;
                root->left=deletion(root->left,temp->data);
            }
            else if(x==2) // Using INORDER SUCCESSOR
            {
                temp=findMin(root->right);
                root->data=temp->data;
                root->right=deletion(root->right,temp->data);
            }
        }
    }
    return root;
}

// Finds the Minimum from the SubTree
BST::Node* BST::findMin(Node* root)
{
    while(root->left!=NULL)
    root=root->left;
    return root;   
}

// Finds the Maximum from the SubTree
BST::Node* BST::findMax(Node* root)
{
    while(root->right!=NULL)
    root=root->right;
    return root;   
}

//  Traversals in the BST
void BST::Traversals()
{
    if(!isEmpty())
    {    
        cout << "1-PREORDER TRAVERSAL\n";
        cout << "2-INORDER TRAVERSAL\n";
        cout << "3-POSTORDER TRAVERSAL\n";
        cout << "Select Option--> ";
        int opt;
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "\nPre-Order--> ";
            preorder(head);
            break;
        case 2:
            cout << "\nIn-Order--> ";
            inorder(head);
            break;
        case 3:
            cout << "\nPost-Order--> ";
            postorder(head);
            break;
        default:
            cout << "\nInvalid Option...";
            break;
        }
        cout << endl << endl;
    }
}

// Implements PREORDER Traversal
void BST::preorder(Node* root)
{
    if(root==NULL)
    return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Implements INORDER Traversal
void BST::inorder(Node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Implements POSTORDER Traversal
void BST::postorder(Node* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Finds the Root/Top Node from the BST.
void BST::Top()
{
    cout << "Top Element--> " << head->data << endl;
}

//  Checks if the BST is Empty or NOT..
bool BST::isEmpty()
{
    if(head==NULL)
    {
        cout << "\nBST is Empty...\n\n";
        return true;
    }
    return false;
}


// Driver Code
int main()
{
    BST* obj=new BST(); // Object of BST Class.
    cout << "# INSTRUCTIONS--> \n";
    cout << "1- Insert\n";
    cout << "2- Delete\n";
    cout << "3- Traversals\n";
    cout << "4- Root\n";
    cout << "Any Character to EXIT!\n\n";
    int n;
    cout << "Enter--> ";
    while(cin >> n)
    {
        if(n==1)
        {
            cout << "Insert--> ";
            int x;
            cin >> x;
            obj->insert(x); // Calling Insert Function
        }
        else if(n==2)
        {
            cout << "Delete--> ";
            int x;
            cin >> x;
            obj->deleteNode(x); // Calling Delete Function
        }
        else if(n==3)
            obj->Traversals(); // Calling Traversal Function
        else if(n==4)
            obj->Top(); // Calling Top Function
        else
            cout << "Choose VALID OPTION!!!\n";    
        cout << "Enter--> ";
    }
    delete(obj);
    return 0;
}