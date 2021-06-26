class Solution {
public:
// RECURSIVE SOLUTION
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* temp=NULL;
        if(l1->val<=l2->val)
        {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }            
        else
        {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        } 
    }

// ITERATIVE SOLUTION
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        ListNode* start=NULL,*last=NULL;
        if(l1->val<=l2->val)
        {
            start=l1;
            last=l1;
            l1=l1->next;
        }
        else
        {
            start=l2;
            last=l2;
            l2=l2->next;
        }
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                last->next=l1;
                l1=l1->next;
                last=last->next;
            }
            else
            {
                last->next=l2;
                l2=l2->next;
                last=last->next;
            }
        }
        while(l1!=NULL)
        {
            last->next=l1;
            l1=l1->next;
            last=last->next;
        }
        while(l2!=NULL)
        {
            last->next=l2;
            l2=l2->next;
            last=last->next;
        }
        return start;
    }
};