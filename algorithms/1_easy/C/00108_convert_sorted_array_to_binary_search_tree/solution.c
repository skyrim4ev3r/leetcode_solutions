static struct TreeNode* arr_to_bst_helper(const int* nums, const ptrdiff_t left, const ptrdiff_t right)
{
    if (left > right) {
        return NULL;
    }

    const ptrdiff_t mid = left + (right - left) / 2;
    struct TreeNode* new_node = (struct TreeNode*) malloc(sizeof(*new_node));
    new_node->val = nums[mid];
    new_node->left = arr_to_bst_helper(nums, left, mid - 1);
    new_node->right = arr_to_bst_helper(nums, mid + 1, right);
    return new_node;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return arr_to_bst_helper(nums, 0, numsSize - 1);
}
