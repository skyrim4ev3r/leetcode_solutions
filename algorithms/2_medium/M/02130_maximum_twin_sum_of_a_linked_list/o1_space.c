static inline ptrdiff_t calc_len(struct ListNode* head)
{
    ptrdiff_t len = 0;
    while (head != NULL) {
        head = head->next;
        len += 1;
    }
    return len;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head)
{
    assert(head != NULL);
    const ptrdiff_t len = calc_len(head);
    assert((len & 1) == 0);
    const ptrdiff_t half = len / 2;

    struct ListNode* h2 = head;
    struct ListNode* h1 = NULL;

    for (ptrdiff_t i = 0; i < half; i += 1) {
        struct ListNode* h2_next = h2->next;
        h2->next = h1;
        h1 = h2;
        h2 = h2_next; 
    }

    struct ListNode* curr1 = h1;
    struct ListNode* curr2 = h2;
    int max = INT_MIN;
    while (curr1 != NULL) {
        const int curr_sum = curr1->val + curr2->val;
        max = curr_sum > max ? curr_sum : max;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    while (h1 != NULL) {
        struct ListNode* h1_next = h1->next;
        h1->next = h2;
        h2 = h1;
        h1 = h1_next; 
    }

    return max;
}
