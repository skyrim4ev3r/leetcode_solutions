/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* right = head;
    for (int i = 0; i < n; ++i) {
        right = right->next;
    }

    struct ListNode* left = head;
    struct ListNode* prev = dummy;
    while (right != NULL) {
        right = right->next;
        prev = left;
        left = left->next;
    }

    prev->next = left->next;

    struct ListNode* new_head = dummy->next;
    free(dummy);
    return new_head;
}
