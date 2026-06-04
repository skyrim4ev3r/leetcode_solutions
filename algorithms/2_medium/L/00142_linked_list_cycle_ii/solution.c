/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static inline struct ListNode* has_cycle(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow;
        }
    }

    return NULL;
}

struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode* hit = has_cycle(head);

    if (hit == NULL) {
        return NULL;
    }

    struct ListNode* ptr1 = head;
    struct ListNode* ptr2 = hit;

    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}
