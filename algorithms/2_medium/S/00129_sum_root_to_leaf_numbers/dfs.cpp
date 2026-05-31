/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    static int dfs(TreeNode* curr, const int prev_sum) {
        if (curr == nullptr) {
            return 0;
        }

        const int curr_sum = prev_sum * 10 + curr->val;
        const bool is_leaf = curr->left == nullptr && curr->right == nullptr;

        if (is_leaf) {
            return curr_sum;
        }

        return dfs(curr->left, curr_sum) + dfs(curr->right, curr_sum);
    }

public:
    static int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
