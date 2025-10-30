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
    int dfs_calculate_max_path_sum(const TreeNode * curr_node, int &max_path_sum) {

        if (curr_node == nullptr) {
            return 0;
        }

        int curr_val = curr_node->val;;
        int left_max_path_sum = std::max(0, dfs_calculate_max_path_sum(curr_node->left, max_path_sum));
        int right_max_path_sum = std::max(0, dfs_calculate_max_path_sum(curr_node->right, max_path_sum));

        int path_sum_from_curr = curr_val + left_max_path_sum + right_max_path_sum;

        max_path_sum = std::max(max_path_sum, path_sum_from_curr);

        return curr_val + std::max(left_max_path_sum, right_max_path_sum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_path_sum = INT_MIN;

        dfs_calculate_max_path_sum(root, max_path_sum);

        return max_path_sum;
    }
};
