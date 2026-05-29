/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(*dummy));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = prev->next;

    while (curr != NULL && curr->next!= NULL) {
        if (curr->val == curr->next->val) {
            const int val_to_skip = curr->val;
            struct ListNode* next_node = curr;

            while (next_node!= NULL && next_node->val == val_to_skip) {
		// No need to delete here — input nodes are owned by caller/test harness.
                next_node = next_node->next;
            }

            curr = next_node;
            prev->next = curr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    struct ListNode* new_head = dummy->next;
    free(dummy);
    return new_head;
}
