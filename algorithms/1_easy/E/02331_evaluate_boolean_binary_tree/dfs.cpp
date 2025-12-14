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
    bool dfs(TreeNode* curr)  {
        if (curr == nullptr) {
            return false;
        }

        switch (curr->val) {
            case 0:
                return false;
            case 1:
                return true;
            case 2:
                return dfs(curr->left) || dfs(curr->right);
            default:
                return dfs(curr->left) && dfs(curr->right);
        }
    }
public:
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};
