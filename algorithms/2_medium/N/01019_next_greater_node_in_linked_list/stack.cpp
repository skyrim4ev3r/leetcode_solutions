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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res{};
        auto curr{ head };

        while (curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }

        const size_t len{ res.size() };
        stack<int> stack{};

        for (size_t i{ len - 1}; i < len; --i) {
            const int curr_val{ res[i] };

            while (!stack.empty() && stack.top() <= curr_val) {
                stack.pop();
            }

            if (stack.empty()) {
                res[i] = 0;
            } else {
                res[i] = stack.top();
            }

            stack.push(curr_val);
        }

        return res;
    }
};
