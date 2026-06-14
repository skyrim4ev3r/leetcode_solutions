/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head)
{
    assert(head != NULL);
    int* nums = NULL;
    size_t nums_len = 0;
    size_t nums_cap = 0;
    struct ListNode dummy = { val: 0, next: head };
    struct ListNode* slow = &dummy;
    struct ListNode* fast = &dummy;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (nums_cap == nums_len) {
            const size_t new_cap = nums_cap == 0 ? 4 : 2 * nums_cap;
            nums = realloc(nums, new_cap * sizeof(*nums));
            assert(nums != NULL);
            nums_cap = new_cap;
        }
        nums[nums_len] = slow->val;
        nums_len += 1;
    }
    
    slow = slow->next;
    ptrdiff_t left_ptr = (ptrdiff_t)nums_len - 1;
    int max = INT_MIN;

    while (slow != NULL) {
        const int curr_sum = nums[left_ptr] + slow->val;
        max = curr_sum > max ? curr_sum : max;
        left_ptr -= 1;
        slow = slow->next;
    }
    
    return max;
}
