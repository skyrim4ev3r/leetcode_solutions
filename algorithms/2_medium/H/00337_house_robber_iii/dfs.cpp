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
    pair<int, int> dfs(TreeNode* curr) {
        if (curr == nullptr) {
            return {0, 0};
        }

        const auto [l_max1, l_max2] = dfs(curr->left);
        const auto [r_max1, r_max2] = dfs(curr->right);

        return {
            l_max2 + r_max2 + curr->val,
            std::max(l_max1, l_max2) + std::max(r_max1, r_max2)
        };
    }
public:
    int rob(TreeNode* root) {
        const auto res{ dfs(root) };

        return std::max(res.first, res.second);
    }
};
