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
    bool dfs(TreeNode* curr, int root_val) {
        if (curr == nullptr) {
            return true;
        }

        if (curr->val != root_val) {
            return false;
        }

        return dfs(curr->left, root_val) && dfs(curr->right, root_val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return dfs(root, root->val);
    }
};
