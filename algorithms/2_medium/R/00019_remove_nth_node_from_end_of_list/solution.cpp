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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* right{head};

        for (int i{0}; i < n; ++i) {
            right = right->next;
        }

        ListNode* left{head};
        ListNode* prev{dummy};

        while (right != nullptr) {
            right = right->next;
            prev = left;
            left = left->next;
        }

        prev->next = left->next;

        ListNode* new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};
