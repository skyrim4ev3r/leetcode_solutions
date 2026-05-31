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
    static int dfs(TreeNode* curr_node, int* max_path_sum) {
        if (curr_node == nullptr) {
            return 0;
        }

        const int curr_val = curr_node->val;;
        const int left_sum = dfs(curr_node->left, max_path_sum);
        const int right_sum = dfs(curr_node->right, max_path_sum);
        const int curr_sum = curr_val + std::max(0, left_sum) + std::max(0, right_sum);

        *max_path_sum = std::max(*max_path_sum, curr_sum);

        const int max_child = std::max(left_sum, right_sum);

        return curr_val + std::max(0, max_child);
    }

public:
    static int maxPathSum(TreeNode* root) {
        int max_path_sum = numeric_limits<int>::min();

        dfs(root, &max_path_sum);

        return max_path_sum;
    }
};
