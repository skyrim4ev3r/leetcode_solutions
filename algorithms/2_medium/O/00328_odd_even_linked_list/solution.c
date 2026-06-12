/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head)
{
    struct ListNode odd_dummy = { val: 0, next: NULL };
    struct ListNode even_dummy = { val: 0, next: NULL };

    struct ListNode* odd_prev = &odd_dummy;
    struct ListNode* even_prev = &even_dummy;
    struct ListNode* curr = head;
    bool is_odd = true;

    while (curr != NULL) {
        struct ListNode* temp = curr;
        curr = curr->next;
        temp->next = NULL;
        
        if (is_odd) {
            odd_prev->next = temp;
            odd_prev = temp;
        } else {
            even_prev->next = temp;
            even_prev = temp;
        }

        is_odd = !is_odd;
    }

    odd_prev->next = even_dummy.next;

    return odd_dummy.next;
}
