/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    static inline void change_val_sign(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr) {
            curr->val *= -1;
            curr = curr->next;
        }
    }

    static inline ListNode* find_first_ngeative_val(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < 0) {
                return curr;
            }

            curr = curr->next;
        }
        return nullptr;
    }
public:
    static ListNode* getIntersectionNode(ListNode *head_a, ListNode *head_b) {
        change_val_sign(head_b);
        const auto intersect = find_first_ngeative_val(head_a);
        change_val_sign(head_b);

        return intersect;
    }
};
