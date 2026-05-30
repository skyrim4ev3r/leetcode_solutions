static int max_depth_helper(struct TreeNode* curr_node)
{
    if (curr_node == NULL) {
        return 0;
    }

    const int max_left = max_depth_helper(curr_node->left);
    const int max_right = max_depth_helper(curr_node->right);
    const int max = max_left > max_right ? max_left : max_right;

    return 1 + max;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root)
{
    return max_depth_helper(root);
}
