/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode dummy1 = { val: 0, next: NULL};
    struct ListNode dummy2 = { val: 0, next: NULL};
    struct ListNode* prev1 = &dummy1;
    struct ListNode* prev2 = &dummy2;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = NULL;

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