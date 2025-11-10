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
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr) {
            return nullptr;
        }

        ListNode* odd_head = new ListNode(0);
        ListNode* even_head = new ListNode(0);

        ListNode* odd_current = odd_head;
        ListNode* even_current = even_head;
        bool is_odd = true;

        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = nullptr;

            if (is_odd) {
                odd_current->next = temp;
                odd_current = temp;
            } else {
                even_current->next = temp;
                even_current = temp;
            }
            is_odd = !is_odd;
        }

        odd_current->next = even_head->next;
        delete even_head;

        ListNode* new_head = odd_head->next;

        delete odd_head;

        return new_head;
    }
};
