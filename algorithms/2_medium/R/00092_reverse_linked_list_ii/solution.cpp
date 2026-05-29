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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dummy = ListNode(0, head);
        auto tail_part_one = &dummy;

        for (int i = 1; i < left; i += 1) {
            tail_part_one = tail_part_one->next;
        }

        auto curr = tail_part_one->next;
        ListNode* head_part_two = nullptr;
        ListNode* tail_part_two = curr;

        for (int i = left; i <= right; i += 1) {
            auto next = curr->next;
            curr->next = head_part_two;
            head_part_two = curr;
            curr = next;
        }

        tail_part_one->next = head_part_two;
        tail_part_two->next = curr;

        return dummy.next;
    }
};
