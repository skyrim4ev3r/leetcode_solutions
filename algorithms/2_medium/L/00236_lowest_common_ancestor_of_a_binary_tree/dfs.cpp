/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* dfs(TreeNode* curr, TreeNode* p, TreeNode* q) {
        if (curr == nullptr || curr == p || curr == q) {
            return curr;
        }

        TreeNode* left = dfs(curr->left, p, q);

        TreeNode* right = dfs(curr->right, p, q);

        if (left != nullptr && right != nullptr) {
            return curr;
        }

        return left == nullptr ? right : left;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        assert(p != nullptr && q != nullptr && root != nullptr && p->val != q->val);
        TreeNode* res = dfs(root, p, q);
        assert(res != nullptr);
        return dfs(root, p, q);
    }
};
