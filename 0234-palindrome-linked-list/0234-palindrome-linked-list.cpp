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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = head;
        while (nextNode != NULL) {
            curr = nextNode;
            nextNode = nextNode->next;
            curr->next = prev;
            prev = curr;
        }
        return curr;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while (second != NULL) {
            if (first->val == second->val) {
                first = first->next;
                second = second->next;
            } else {
                reverseLL(newHead);
                return false;
            }
        }
        reverseLL(newHead);
        return true;
    }
};