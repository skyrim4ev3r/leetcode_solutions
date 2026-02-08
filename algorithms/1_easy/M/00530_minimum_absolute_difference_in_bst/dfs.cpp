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
    tuple<int, int, int> dfs(TreeNode* curr) {
        const int val{ curr->val };
        int max{ val };
        int min{ val };
        int min_diff{ numeric_limits<int>::max() };

        if (curr->left != nullptr) {
            const auto [min_left, max_left, min_diff_left] = dfs(curr->left);
            min = min_left;
            min_diff = std::min(val - max_left, min_diff_left);
        }

        if (curr->right != nullptr) {
            const auto [min_right, max_right, min_diff_right] = dfs(curr->right);
            max = max_right;
            min_diff = std::min(min_diff, std::min(min_right - val, min_diff_right));
        }

        return { min, max, min_diff };
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            throw "unreachable!()";
        }

        const auto [_c0, _c1, min_diff] = dfs(root);

        return min_diff;
    }
};
