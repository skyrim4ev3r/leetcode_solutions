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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res_head = nullptr;
        ListNode* res_curr = nullptr;

        ListNode* curr = head->next;
        int sum{0};

        while (curr != nullptr) {
            sum += curr->val;
            curr = curr->next;

            if (curr != nullptr && curr->val == 0) {
                ListNode* new_node = new ListNode(sum);
                sum = 0;
                if (res_head == nullptr) {
                    res_head = new_node;
                    res_curr = res_head;
                } else {
                    res_curr->next = new_node;
                    res_curr = res_curr->next;
                }
            }
        }

        return res_head;
    }
};
