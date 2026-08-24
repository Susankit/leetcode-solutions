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
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head;
        ListNode *Next = curr->next;
        ListNode *prev = NULL;
        while(Next != NULL) {
            curr->next = prev;
            prev = curr;
            curr = Next;
            Next = Next->next;
        }
        curr->next = prev;
        return curr;
    }

    ListNode *getkth(ListNode* head, int k) {
        k -= 1;
        ListNode* temp = head;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        // ListNode* nextnode = head;
        ListNode* prevnode = NULL;
        while (temp != NULL) {
            ListNode *kth = getkth(temp, k);
            if (kth == NULL) {
                if(prevnode) {
                    prevnode->next = temp;
                }
                break;
            }
            ListNode* nextnode = kth->next;
            kth->next = NULL;
            reverse(temp);
            if (temp == head) {
                head = kth;
            } else {
                prevnode->next = kth;
            }
            prevnode = temp;
            temp = nextnode;
        }
        return head;
    }
};