// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.
// It is guaranteed that there are no cycles anywhere in the entire linked structure.
// Note that the linked lists must retain their original structure after the function returns.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>m;
        while(headA!=NULL)
        {
            m[headA]=1;
            headA=headA->next;
        }
        while(headB!=NULL)
        {
            if(m[headB]==1)
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
};

// ANOTHER METHOD- SPACE O(1)
// 1. Get the length of the two lists.
// 2. Align them to the same start point.
// 3. Move them together until finding the intersection point, or the end null