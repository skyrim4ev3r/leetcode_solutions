/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static inline void change_val_sign(struct ListNode* head)
{
    struct ListNode* curr = head;
    while (curr != NULL) {
        curr->val *= -1;
        curr = curr->next;
    }
}

static inline struct ListNode* find_first_ngeative_val(struct ListNode* head)
{
    struct ListNode* curr = head;
    while (curr != NULL) {
        if (curr->val < 0) {
            return curr;
        }

        curr = curr->next;
    }
    return NULL;
}

struct ListNode *getIntersectionNode(struct ListNode *head_a, struct ListNode *head_b)
{
    change_val_sign(head_b);
    const struct ListNode* intersect = find_first_ngeative_val(head_a);
    change_val_sign(head_b);

    return intersect;
}
