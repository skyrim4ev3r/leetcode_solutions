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

        int count{0};
        ListNode* curr{head};

        while (curr != nullptr) {
            count += 1;
            curr = curr->next;
        }

        curr = head;
        int half{count / 2};

        for (int i{1}; i < half; ++i) {
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = nullptr;
        curr = temp;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* head1{head};
        ListNode* head2{prev};
        int max{INT_MIN};

        // len of head1 and head2 are equal, so checking only one of them is enough
        while (head1 != nullptr) {
            max = std::max(max, head1->val + head2->val);
            head1 = head1->next;
            head2 = head2->next;
        }

        return max;
    }
};
