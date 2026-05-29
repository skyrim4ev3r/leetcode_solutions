static bool dfs(struct TreeNode* curr_node, int64_t min_val, int64_t max_val)
{
    if (curr_node == NULL) {
        return true;
    }

    return curr_node->val > min_val && curr_node->val < max_val &&
            dfs(curr_node->left, min_val, curr_node->val) &&
            dfs(curr_node->right, curr_node->val, max_val);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root)
{
    return dfs(root, INT64_MIN, INT64_MAX);
}
