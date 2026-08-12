/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA, *t2 = headB;
        int N1 = 0, N2 = 0;
        while (t1 != NULL) {
            N1++;
            t1 = t1->next;
        }
        while (t2 != NULL) {
            N2++;
            t2 = t2->next;
        }
        t1 = headA;
        t2 = headB;
        int d = max(N1, N2) - min(N1, N2);
        for (int i=0; i<d; i++) {
            if (N1 < N2) {
                t2 = t2->next;
            } else {
                t1 = t1->next;
            }
        }
        while (t1 != NULL && t2 != NULL) {
            if (t1 == t2) {
                return t1;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;
    }
};