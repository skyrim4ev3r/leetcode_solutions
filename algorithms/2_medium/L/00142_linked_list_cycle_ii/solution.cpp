/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    static ListNode* has_cycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return slow;
            }
        }

        return nullptr;
    }
public:
    static ListNode* detectCycle(ListNode* head) {
        ListNode* hit = has_cycle(head);

        if (hit == nullptr) {
            return nullptr;
        }

        ListNode* ptr1 = head;
        ListNode* ptr2 = hit;

        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return ptr1;
    }
};
