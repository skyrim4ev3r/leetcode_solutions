static inline struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode* curr = head;
    struct ListNode* new_head = NULL;

    while (curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = new_head;
        new_head = curr;
        curr = next;
    }

    return new_head;
}

static inline size_t calc_len(struct ListNode* head)
{
    size_t len = 0;
    struct ListNode* curr = head;
    while (curr != NULL) {
        len += 1;
        curr = curr->next;
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
void reorderList(struct ListNode* head)
{
    if (head == NULL) { 
        return;
    }

    const size_t len = calc_len(head);
    struct ListNode* h1 = head;
    struct ListNode* h2 = NULL;
    struct ListNode* curr = head;
    const size_t mid = (len + 1) / 2;

    for (size_t i = 1; i < mid; i += 1) {
        curr = curr->next;
    }

    h2 = curr->next;
    curr->next = NULL;

    h2 = reverse(h2);

    struct ListNode dummy = { val: 0, next: NULL };
    struct ListNode* prev = &dummy;

    while (h1 != NULL && h2 != NULL) {
        prev->next = h1; // first time: dummy.next = original head
        prev = h1;
        h1 = h1->next;

        prev->next = h2;
        prev = h2;
        h2 = h2->next;
    }

    prev->next = h1;
}
