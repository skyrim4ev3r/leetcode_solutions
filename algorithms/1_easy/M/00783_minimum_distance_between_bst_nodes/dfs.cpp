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
    pair<int, int> dfs(TreeNode* curr, int &min_diff) {
        const int val{curr->val};
        int min{val};
        int max{val};

        if (curr->left != nullptr) {
            auto left_res = dfs(curr->left, min_diff);
            min_diff = std::min(min_diff, val - left_res.second);
            min = left_res.first;
        }

        if (curr->right != nullptr) {
            auto right_res = dfs(curr->right, min_diff);
            min_diff = std::min(min_diff, right_res.first - val);
            max = right_res.second;
        }

        return {min, max};
    }
public:
    int minDiffInBST(TreeNode* root) {
        int min_diff{numeric_limits<int>::max()};

        dfs(root, min_diff);

        return min_diff;
    }
};
