// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by
// continuously following the next pointer. Internally, pos is used to denote the index of the node
// that tails next pointer is connected to. Note that pos is not passed as a parameter.
// Notice that you should not modify the linked list.


// Space O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow,*fast;
        slow=fast=head;
        int f=0;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                f=1;
                break;
            }
        }
        if(f==0)
            return NULL;
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};