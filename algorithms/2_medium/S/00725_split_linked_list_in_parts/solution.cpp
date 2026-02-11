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
    static inline int calc_len(ListNode* curr) {
        int len{ 0 };
        while (curr != nullptr) {
            curr = curr->next;
            len += 1;
        }
        return len;
    }
public:
    static vector<ListNode*> splitListToParts(ListNode* head, int k) {
        const int len{ calc_len(head) };
        const int seg_len{ len / k };
        int extra{ len % k };
        auto curr{ head };
        auto dummy = new ListNode(0);
        const size_t k_usize{ static_cast<size_t>(k) };
        vector<ListNode*> res(k_usize, nullptr);

        for (size_t i{ 0 }; i < k_usize; ++i) {
            auto prev{ dummy };
            const int target_len{ seg_len + ((extra > 0) ? 1 : 0) };

            if (extra > 0) {
                extra -= 1;
            }

            if (target_len == 0) {
                break;
            }

            for (int c{ 0 }; c < target_len; ++c) {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
                prev->next = nullptr;
            }

            res[i] = dummy->next;
            dummy->next = nullptr;
        }

        return res;
    }
};
