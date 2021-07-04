// Given the head of a linked list, rotate the list to the right by k places.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode *ptr=head,*h=head;
        int len=1;
        while(ptr->next)
            len++,ptr=ptr->next;
        ptr->next=head;
        if(k%=len)
        {
            for(int i=0;i<len-k;i++)
            ptr=ptr->next;
        }
        h=ptr->next;
        ptr->next=NULL;
        return h;
    }
};