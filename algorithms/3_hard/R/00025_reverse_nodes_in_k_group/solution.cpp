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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        stack<int> stack;

        auto l_ptr = head;
        auto r_ptr = head;
        while (r_ptr != nullptr) {
            stack.push(r_ptr->val);
            r_ptr = r_ptr->next;
            if (stack.size() == k) {
                while (l_ptr != r_ptr) {
                    l_ptr->val = stack.top();
                    stack.pop();
                    l_ptr = l_ptr->next;
                }
            }
        }

        return head;
    }

};
