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
        vector<int> nums{};

        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        size_t left{0};
        size_t right{nums.size() - 1};
        int max = INT_MIN;

        while (left < right) {
            max = std::max(max, nums[left] + nums[right]);
            left += 1;
            right -= 1;
        }

        return max;
    }
};
