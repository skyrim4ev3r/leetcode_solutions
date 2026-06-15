/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head)
{
    assert(head != NULL);
    struct ListNode dummy = { val: 0, next: head };
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return dummy.next;
}
