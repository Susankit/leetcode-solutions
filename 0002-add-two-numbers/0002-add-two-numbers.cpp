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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* temp1 = l1, *temp2 = l2;
        int carry = 0, sum  = 0 ;
        while (temp1 != NULL || temp2 != NULL) {
            sum = 0;
            sum = sum + carry;
            if (temp1 != NULL) sum = sum + temp1->val;
            if (temp2 != NULL) sum = sum + temp2->val;
            ListNode* newNode = new ListNode (sum % 10);
            carry = sum / 10;
            temp->next = newNode;
            temp = temp->next;
            if (temp1 != NULL) temp1 = temp1->next;
            if (temp2 != NULL) temp2 = temp2->next;
        }
        if (carry != 0) {
            ListNode* newNode = new ListNode (carry);
            temp->next = newNode;
        }
        return dummy->next;
    }
};