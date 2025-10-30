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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> nums_map;
        for (auto &head: lists) {
            while (head != nullptr) {
                nums_map[head->val] += 1;
                head = head->next;
            }
        }

        ListNode* head = nullptr;
        for (auto it{nums_map.rbegin()}; it != nums_map.rend(); ++it) {
            int val = it->first;
            for (int i{0}; i < it->second; ++i) {
                auto new_node = new ListNode(val);
                new_node->next = head;
                head = new_node;
            }
        }

        return head;
    }
};
