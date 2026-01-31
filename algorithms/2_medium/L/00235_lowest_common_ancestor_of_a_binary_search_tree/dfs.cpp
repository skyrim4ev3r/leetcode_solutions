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
    pair<bool, bool> dfs(
        TreeNode* curr,
        TreeNode* p,
        TreeNode* q,
        TreeNode* &res
    ) {
        if (curr == nullptr || res != nullptr) {
            return make_pair(false, false);
        }

        const auto left_res{ dfs(curr->left, p, q, res) };
        const auto right_res{ dfs(curr->right, p, q, res) };
        const bool found_p{ left_res.first || right_res.first || curr == p};
        const bool found_q{ left_res.second || right_res.second || curr == q};

        if (res == nullptr && found_p && found_q) {
            res = curr;
        }

        return make_pair(found_p, found_q);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res{ nullptr };

        dfs(root, p, q, res);

        return res;
    }
};
