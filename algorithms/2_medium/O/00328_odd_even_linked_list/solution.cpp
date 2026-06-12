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
        auto odd_dummy = ListNode(0);
        auto even_dummy = ListNode(0);

        auto* odd_prev = &odd_dummy;
        auto* even_prev = &even_dummy;
        auto* curr = head;
        bool is_odd = true;

        while (curr != nullptr) {
            auto* temp = curr;
            curr = curr->next;
            temp->next = nullptr;

            if (is_odd) {
                odd_prev->next = temp;
                odd_prev = temp;
            } else {
                even_prev->next = temp;
                even_prev = temp;
            }

            is_odd = !is_odd;
        }

        odd_prev->next = even_dummy.next;

        return odd_dummy.next;
    }
};
