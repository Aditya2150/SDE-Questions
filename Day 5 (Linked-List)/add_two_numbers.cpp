// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

class Solution {   
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(),*curr=head;
        int carry=0,sum=0;
        while(l1!=NULL || l2!=NULL)
        {
            int x=(l1!=NULL?l1->val:0);
            int y=(l2!=NULL?l2->val:0);
            sum=x+y+carry;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
            carry=sum/10;
            if(l1!=NULL)l1=l1->next;
            if(l2!=NULL)l2=l2->next;
        }
        if(carry>0)
            curr->next=new ListNode(carry);
        return head->next;
    }
};