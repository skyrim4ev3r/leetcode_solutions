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
    int dfs(TreeNode* curr, int curr_sum) {
        if (curr == nullptr) {
            return 0;
        }

        if (curr->left == nullptr && curr->right == nullptr) {
            return curr_sum * 10 + curr->val;
        }

        return dfs(curr->left, curr_sum * 10 + curr->val) +
               dfs(curr->right, curr_sum * 10 + curr->val);
    }

public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
