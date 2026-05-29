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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = prev->next;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                const int val_to_skip = curr->val;
                ListNode* next_node = curr;

                while (next_node!= nullptr && next_node->val == val_to_skip) {
                    // No need to delete here — input nodes are owned by caller/test harness.
                    next_node = next_node->next;
                }

                curr = next_node;
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};
