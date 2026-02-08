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
    static inline pair<int, int> calc_len_and_shift_count(ListNode* head, int k) {
        int len{ 0 };
        auto curr{ head };

        while (curr != nullptr) {
            len += 1;
            curr = curr->next;
        }

        const int shift_count{ len == 0 ? 0 : (len - k % len) % len };

        return {len, shift_count};
    }

    static inline pair<ListNode*, ListNode*> split_into_two_list(ListNode* head, int shift_count) {
        auto curr{ head };

        for (int i{ 0 }; i < shift_count - 1; ++i) {
            curr = curr->next;
        }

        auto head2{ curr->next };
        curr->next = nullptr;

        return {head, head2};
    }
public:
    static ListNode* rotateRight(ListNode* head, int k) {
        const auto [len, shift_count] = calc_len_and_shift_count(head, k);

        if (len <= 1 || shift_count == 0) {
            return head;
        }

        auto [h1, h2] = split_into_two_list(head, shift_count);
        auto curr{ h2 };

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = h1;

        return h2;
    }
};
