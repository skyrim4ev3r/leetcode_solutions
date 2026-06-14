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
    static inline ptrdiff_t calc_len(ListNode* head) {
        ptrdiff_t len = 0;
        while (head != nullptr) {
            head = head->next;
            len += 1;
        }
        return len;
    }

public:
    int pairSum(ListNode* head) {
        assert(head != nullptr);
        const ptrdiff_t len = calc_len(head);
        assert((len & 1) == 0);
        const ptrdiff_t half = len / 2;

        ListNode* h2 = head;
        ListNode* h1 = nullptr;

        for (ptrdiff_t i = 0; i < half; i += 1) {
            ListNode* h2_next = h2->next;
            h2->next = h1;
            h1 = h2;
            h2 = h2_next; 
        }

        ListNode* curr1 = h1;
        ListNode* curr2 = h2;
        int max = INT_MIN;
        while (curr1 != nullptr) {
            const int curr_sum = curr1->val + curr2->val;
            max = std::max(max, curr_sum);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while (h1 != nullptr) {
            ListNode* h1_next = h1->next;
            h1->next = h2;
            h2 = h1;
            h1 = h1_next; 
        }

        return max;
    }
};
