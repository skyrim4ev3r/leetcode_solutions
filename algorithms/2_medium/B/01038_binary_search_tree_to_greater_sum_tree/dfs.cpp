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
    void dfs(TreeNode* curr, int &sum) {
        if (curr == nullptr) {
            return;
        }

        dfs(curr->right, sum);
        sum += curr->val;
        curr->val = sum;
        dfs(curr->left, sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum{0};
        dfs(root, sum);
        return root;
    }
};
