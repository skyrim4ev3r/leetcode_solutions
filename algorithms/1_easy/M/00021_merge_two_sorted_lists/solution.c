/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* prev = dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            prev->next = list1;
            prev = list1;
            list1 = list1->next;
        } else {
            prev->next = list2;
            prev = list2;
            list2 = list2->next;
        }
    }

    prev->next = list1 == NULL ? list2 : list1;
    struct ListNode* new_head = dummy->next;
    free(dummy);
    return new_head;
}
