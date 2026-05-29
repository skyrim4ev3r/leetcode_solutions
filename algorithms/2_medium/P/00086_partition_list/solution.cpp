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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1 = ListNode(0);
        ListNode dummy2 = ListNode(0);
        ListNode* prev1 = &dummy1;
        ListNode* prev2 = &dummy2;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = nullptr;

            if (curr->val < x) {
                prev1->next= curr;
                prev1 = curr;
            } else {
                prev2->next= curr;
                prev2 = curr;
            }

            curr = next;
        }

        prev1->next = dummy2.next;

        return dummy1.next;
    }
};