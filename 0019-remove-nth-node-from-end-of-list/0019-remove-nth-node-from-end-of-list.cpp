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
    int lengthOfLL (ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        int cnt = 0;
        if (head == NULL) {
            return head;
        }
        if (head->next == NULL && n == 1) {
            delete(temp);
            return NULL;
        }
        int len = lengthOfLL(head);
        if (n == len) {
            head = head->next;
            delete(temp);
            return head;
        }
        while (temp != NULL) {
            cnt++;
            if (cnt == len- n + 1) {
                prev->next = temp->next;
                delete(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};