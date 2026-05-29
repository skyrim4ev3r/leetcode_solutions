/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->val == curr->next->val)  {
            // No need to delete here — input nodes are owned by caller/test harness.
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }

    return head;
}