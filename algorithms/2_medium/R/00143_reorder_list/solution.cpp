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
    static inline ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* new_head = nullptr;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = new_head;
            new_head = curr;
            curr = next;
        }

        return new_head;
    }

    static inline size_t calc_len(ListNode* head) {
        size_t len = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            len += 1;
            curr = curr->next;
        }
        return len;
    }
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) { 
            return;
        }

        const size_t len = calc_len(head);
        ListNode* h1 = head;
        ListNode* h2 = nullptr;
        ListNode* curr = head;
        const size_t mid = (len + 1) / 2;

        for (size_t i = 1; i < mid; i += 1) {
            curr = curr->next;
        }

        h2 = curr->next;
        curr->next = nullptr;

        h2 = reverse(h2);

        auto dummy = ListNode(0);
        auto prev = &dummy;

        while (h1 != nullptr && h2 != nullptr) {
            prev->next = h1; // first time: dummy.next = original head
            prev = h1;
            h1 = h1->next;

            prev->next = h2;
            prev = h2;
            h2 = h2->next;
        }

        prev->next = h1;
    }
};
