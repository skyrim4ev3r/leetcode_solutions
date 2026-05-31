static int dfs(struct TreeNode* curr, const int prev_sum)
{
        if (curr == NULL) {
            return 0;
        }

        const int curr_sum = prev_sum * 10 + curr->val;
        const bool is_leaf = curr->left == NULL && curr->right == NULL;

        if (is_leaf) {
            return curr_sum;
        }

        return dfs(curr->left, curr_sum) + dfs(curr->right, curr_sum);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root)
{
    return dfs(root, 0);
}
