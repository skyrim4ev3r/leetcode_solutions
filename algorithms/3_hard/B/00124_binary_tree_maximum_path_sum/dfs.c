static inline int max(int a, int b)
{
    return a > b ? a : b;
}

static int dfs(struct TreeNode* curr_node, int* max_path_sum)
{
    if (curr_node == NULL) {
        return 0;
    }

    const int curr_val = curr_node->val;
    const int left_sum = dfs(curr_node->left, max_path_sum);
    const int right_sum = dfs(curr_node->right, max_path_sum);
    const int curr_sum = curr_val + max(0, left_sum) + max(0, right_sum);

    *max_path_sum = max(*max_path_sum, curr_sum);

    const int max_child = max(left_sum, right_sum);

    return curr_val + max(0, max_child);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSum(struct TreeNode* root)
{
    int max_path_sum = INT_MIN;

    dfs(root, &max_path_sum);

    return max_path_sum;
}
