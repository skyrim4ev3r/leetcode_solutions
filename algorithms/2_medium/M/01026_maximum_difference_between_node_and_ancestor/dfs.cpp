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
    pair<int, int> dfs(TreeNode* curr, int& max_diff) {
        const int curr_val{ curr->val };
        int curr_max{ curr_val };
        int curr_min{ curr_val };

        if (curr->left != nullptr)  {
            const auto [left_min, left_max] = dfs(curr->left, max_diff);
            curr_min = min(curr_min, left_min);
            curr_max = max(curr_max, left_max);
        }

        if (curr->right != nullptr) {
            const auto [right_min, right_max] = dfs(curr->right, max_diff);
            curr_min = min(curr_min, right_min);
            curr_max = max(curr_max, right_max);
        }

        max_diff = std::max(max_diff, std::max(curr_val - curr_min, curr_max - curr_val));

        return {curr_min, curr_max};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int max_diff{ numeric_limits<int>::min() };

        if (root != nullptr) {
            dfs(root, max_diff);
        }

        return max_diff;
    }
};
