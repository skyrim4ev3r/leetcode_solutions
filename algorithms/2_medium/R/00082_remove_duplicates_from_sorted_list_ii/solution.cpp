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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy{ new ListNode(0) };
        dummy->next = head;
        ListNode* prev{ dummy };

        while (prev != nullptr) {
            ListNode* curr{ prev->next };

            if (curr != nullptr && curr->next != nullptr) {
                if (curr->val == curr->next->val) {
                    const int val_to_del{ curr->val };

                    while (curr != nullptr && curr->val == val_to_del) {
                        curr = curr->next;
                    }

                    prev->next = curr;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            } else {
                break;
            }
        }

        ListNode* new_head{ dummy->next };
        delete dummy;
        return new_head;
    }
};
