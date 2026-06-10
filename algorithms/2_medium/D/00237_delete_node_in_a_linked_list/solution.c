/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node)
{
    assert(node != NULL && node->next != NULL);
    struct ListNode* next = node->next;
    node->val = next->val;
    node->next = next->next;
    free(next);
}
