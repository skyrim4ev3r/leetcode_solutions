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
    int pairSum(ListNode* head) {
        assert(head != nullptr);
        auto nums = vector<int>();
        struct ListNode dummy = ListNode(0);
        dummy.next = head;
        struct ListNode* slow = &dummy;
        struct ListNode* fast = &dummy;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            nums.push_back(slow->val);
        }
        
        slow = slow->next;
        int max = INT_MIN;

        while (slow != nullptr) {
            const int curr_sum = nums.back() + slow->val;
            max = std::max(curr_sum, max);
            nums.pop_back();
            slow = slow->next;
        }
        
        return max;
    }
};
