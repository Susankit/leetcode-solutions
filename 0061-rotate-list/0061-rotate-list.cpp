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
    int lengthofLL(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *temp1 = head, *temp2 = head;
        ListNode *newhead = nullptr;
        int cnt = 1;
        int length = lengthofLL(head);
        k = k % length;
        if (k == 0) {
            return head;
        }
        int size = length - k;
        while(temp2 != NULL) {
            if (cnt == size) {
                newhead = temp2->next;
                temp2->next = NULL;
                break;
            }
            cnt++;
            temp2 = temp2->next; 
        }
        ListNode* temp3 = newhead;
        while(temp3->next != NULL) {
            temp3 = temp3->next;
        }
        temp3->next = temp1;
        return newhead;
    }
};