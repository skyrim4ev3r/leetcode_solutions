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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = nullptr;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
            prev = slow;
            slow = slow->next;
        }

        prev->next = slow->next;

        ListNode* new_head = dummy->next;
        delete dummy;

        return new_head;
    }
};
