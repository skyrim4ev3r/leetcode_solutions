static bool has_path_sum_helper(struct TreeNode* curr_node, const int prev_sum, const int target_sum)
{
    if (curr_node == NULL) {
        return false;
    }

    const bool is_leaf = (curr_node->left == NULL) && (curr_node->right == NULL);
    const int curr_sum = prev_sum + curr_node->val;

    return (is_leaf && curr_sum == target_sum) || 
            has_path_sum_helper(curr_node->left, curr_sum, target_sum) ||
            has_path_sum_helper(curr_node->right, curr_sum, target_sum);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum)
{
    const int curr_sum = 0;
    return has_path_sum_helper(root, curr_sum, targetSum);
}
