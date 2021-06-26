// Given the head of a singly linked list, return true if it is a palindrome.

// Space O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>v;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        int i=0,j=v.size()-1;
        while(i<j)
        {
            if(v[i++]!=v[j--])
                return false;
        }
        return true;
    }
};

// Space O(1)
class Solution {
    ListNode* reverse_list(ListNode* head)
    {
        ListNode* prev=NULL,*curr=head;
        while(curr!=NULL)
        {
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow,* fast;
        slow=fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast!=NULL) // For ODD Nodes
            slow=slow->next;
        slow=reverse_list(slow);
        fast=head;
        while(slow!=NULL)
        {
            if(fast->val!=slow->val)
                return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};