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
    bool isPalindrome(ListNode* head) {

        int count{0};
        ListNode* curr{head};

        while (curr !=  nullptr) {
            count += 1;
            curr = curr->next;
        }

        if (count == 1) {
            return true;
        }

        int mid{count / 2};
        curr = head;

        for (int i{1}; i < mid; ++i) {
            curr = curr->next;
        }

        ListNode* next{curr->next};
        curr->next = nullptr;
        if ((count & 1) == 1) {
            next = next->next;
        }

        ListNode* prev{nullptr};

        while (next != nullptr) {
            ListNode* node = next;
            next = node->next;
            node->next = prev;
            prev = node;
        }

        ListNode* head1{head};
        ListNode* head2{prev};

        // head1 and head2 have the same len, so checking one of them is enough.
        while (head1 != nullptr) {
            if (head1->val != head2->val) {
                return false; // If values don't match, then it is not a palindrome
            }

            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};
