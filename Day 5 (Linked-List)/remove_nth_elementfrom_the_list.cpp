// Given the head of a linked list, remove the nth node from the end of the list and return its head.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ahead=head;
        while(n)
        {
            ahead=ahead->next;
            n--;
        }
        ListNode* node=head,*prev=NULL;
        while(ahead!=NULL)
        {
            prev=node;
            node=node->next;
            ahead=ahead->next;
        }
        if(prev!=NULL)
            prev->next=node->next;
        else
            head=node->next;
        delete(node);
        node=nullptr;
        return head;
    }
};