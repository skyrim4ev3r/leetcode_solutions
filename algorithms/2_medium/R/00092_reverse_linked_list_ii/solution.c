/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    struct ListNode dummy = { val: 0, next: head};
    struct ListNode* tail_part_one = &dummy;

    for (int i = 1; i < left; i += 1) {
        tail_part_one = tail_part_one->next;
    }

    struct ListNode* curr = tail_part_one->next;
    struct ListNode* head_part_two = NULL;
    struct ListNode* tail_part_two = curr;

    for (int i = left; i <= right; i += 1) {
        struct ListNode* next = curr->next;
        curr->next = head_part_two;
        head_part_two = curr;
        curr = next;
    }

    tail_part_one->next = head_part_two;
    tail_part_two->next = curr;

    return dummy.next;
}
