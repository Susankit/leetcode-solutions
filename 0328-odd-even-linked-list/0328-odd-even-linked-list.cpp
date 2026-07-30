/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (odd != NULL) {
            ListNode* newnode = new ListNode(odd->val);
            temp->next = newnode;
            temp = temp->next;
            if (odd->next != NULL) odd = odd->next->next;
            else odd = NULL;
        }
        while (even != NULL) {
            ListNode* newnode = new ListNode(even->val);
            temp->next = newnode;
            temp = temp->next;
            if (even->next != NULL) even = even->next->next;
            else even = NULL;
        }
        return dummy->next;
    }
};