// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
// Note: The flattened list will be printed using the bottom pointer instead of next pointer

#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
 
    

// Merge Time-O(n*m) Space-O(1)    
Node * merge(Node* l1,Node* l2)
{
    if(l1==NULL)
    return l2;
    if(l2==NULL)
    return l1;
    if(l1->data<=l2->data)
    {
        l1->bottom=merge(l1->bottom,l2);
        l1->next=NULL;
        return l1;
    }
    else
    {
        l2->bottom=merge(l1,l2->bottom);
        l2->next=NULL;
        return l2;
    }
}

    
Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL)
    return root;
    root->next=flatten(root->next);
    root=merge(root,root->next);
    return root;
}




//USING HEAP Time-O(n*logk) space-O(n)   

struct compare {
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};
        
 
Node *flatten(Node *root)
{
    priority_queue<Node*,vector<Node*>,compare> pq;
    Node* ptr=root;
    Node* head;
    while(ptr!=NULL)
    {
        pq.push(ptr);
        ptr=ptr->next;
    }
    
    while(!pq.empty())
    {
        Node* temp=pq.top();
        pq.pop();
        if(temp->bottom!=NULL)
        pq.push(temp->bottom);
        
        if(head==NULL)
        {
            head=temp;
            ptr=temp;
            ptr->next=NULL;
        }
        else
        {
            ptr->bottom=temp;
            ptr=temp;
            ptr->next=NULL;
        }
    }
    // ptr->next=NULL;
    // ptr->bottom=NULL;
    return head;
    
}