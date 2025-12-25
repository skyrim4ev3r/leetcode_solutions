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
    void dfs(TreeNode* curr, int& val) {
        if (curr == nullptr) {
            return;
        }

        dfs(curr->right, val);
        curr->val += val;
        val = curr->val;
        dfs(curr->left, val);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int val{0};
        dfs(root, val);

        return root;
    }
};
