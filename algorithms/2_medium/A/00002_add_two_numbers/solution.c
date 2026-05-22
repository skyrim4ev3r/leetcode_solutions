/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static inline struct ListNode* create_new_node(const int val)
{
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;
}

static inline struct ListNode* delete_and_get_next(struct ListNode* l)
{
    if (l == NULL) {
        return NULL;
    }

    struct ListNode* tmp_node = l;
    l = l->next;
    free(tmp_node);
    return l;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* res_dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    res_dummy->next = NULL;
    res_dummy->val = 0;
    struct ListNode* res_prev = res_dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL) {
        const int sum_num = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
        l1 = delete_and_get_next(l1);
        l2 = delete_and_get_next(l2);
        struct ListNode* new_node = create_new_node(sum_num % 10);
        carry = sum_num / 10;
        res_prev->next = new_node;
        res_prev = new_node;
    }

    if (carry > 0) {
        struct ListNode* new_node = create_new_node(carry);
        res_prev->next = new_node;
    }

    struct ListNode* res_head = res_dummy->next;
    free(res_dummy);
    return res_head;
}
