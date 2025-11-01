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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hashset(nums.begin(), nums.end());

        ListNode* dummy{new ListNode(0)};
        dummy->next = head;

        ListNode* prev{dummy};
        ListNode* curr{dummy->next};

        while (curr != nullptr) {
            if (hashset.find(curr->val) == hashset.end()) {
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }
        }

        ListNode* new_head{dummy->next};
        delete dummy;

        return new_head;
    }
};
