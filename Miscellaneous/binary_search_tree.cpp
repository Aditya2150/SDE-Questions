#include<bits/stdc++.h>
using namespace std;

class BST{
public:
    class Node{
    public:    
        int data;
        Node* left;
        Node* right;
        Node(int x)
        {
            data=x;
            left=NULL;
            right=NULL;
        }
    };
    BST()
    {
        cout << "\n\n..............Welcome to BST Implementation..............\n\n";
    }
    Node* insert(Node*,int);
    Node* deleteNode(Node*,int);
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
    Node* findMin(Node*);
    Node* findMax(Node*);
};

BST::Node* BST::insert(Node* root,int val)
{
    if(root==NULL)
        root=new Node(val);
    else if(root->data<val)
        root->right=insert(root->right,val);
    else
        root->left=insert(root->left,val);
    return root;    
}

BST::Node* BST::deleteNode(Node* root,int val)
{
    if(root->data>val)
    root->left=deleteNode(root->left,val);
    else if(root->data<val)
    root->right=deleteNode(root->right,val);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            root=NULL;
            return root;
        }
        else if (root->left==NULL) 
        {
            Node* temp=root;
            root=root->right;
            delete(temp);
            return root;
        }
        else if (root->right==NULL) 
        {
            Node* temp=root;
            root=root->left;
            delete(temp);
            return root;
        }
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
            if(x==1)
            {
                temp=findMax(root->left);
                root->data=temp->data;
                root->left=deleteNode(root->left,temp->data);
            }
            else if(x==2)
            {
                temp=findMin(root->right);
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
            }
        }
    }
    return root;
}


BST::Node* BST::findMin(Node* root)
{
    while(root->left!=NULL)
    root=root->left;
    return root;   
}

BST::Node* BST::findMax(Node* root)
{
    while(root->right!=NULL)
    root=root->right;
    return root;   
}

void BST::preorder(Node* root)
{
    if(root==NULL)
    return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void BST::inorder(Node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void BST::postorder(Node* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


int main()
{
    BST* obj=new BST();
    BST::Node* head=NULL;
    unordered_map<int,int>m;
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
            if(m.find(x)==m.end())
            {
                head=obj->insert(head,x);
                m[x]=1;
            }
            else
            cout << "Element Already Exist in BST!!!!!\n";
        }
        else if(n==2)
        {
            if(head==NULL)
                cout << "\nBST is Empty...\n\n";
            else
            {
                cout << "Delete--> ";
                int x;
                cin >> x;
                if(m.find(x)==m.end())
                    cout << "Node doesn't EXIST!!!\n";
                else
                {
                    head=obj->deleteNode(head,x);
                    m.erase(x);
                    cout << "Node Deleted SuccessFully!!!\n";
                }    
            }    
        }
        else if(n==3)
        {
            if(head==NULL)
                cout << "\nBST is Empty...\n\n";
            else
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
                    obj->preorder(head);
                    cout << endl << endl;
                    break;
                case 2:
                    cout << "\nIn-Order--> ";
                    obj->inorder(head);
                    cout << endl << endl; 

                    break;
                case 3:
                    cout << "\nPost-Order--> ";
                    obj->postorder(head);
                    cout << endl << endl;
                    break;
                default:
                    cout << "\nInvalid Option...\n";
                    break;
                }
            }
        }
        else if(n==4)
            cout << "Root Element--> " << head->data << endl;
        cout << "Enter--> ";
    }
    delete(head);
    delete(obj);
    return 0;
}