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
    static bool has_path_sum_helper(TreeNode* curr_node, const int prev_sum, const int target_sum) {
        if (curr_node == nullptr) {
            return false;
        }

        const bool is_leaf = (curr_node->left == nullptr) && (curr_node->right == nullptr);
        const int curr_sum = prev_sum + curr_node->val;

        return (is_leaf && curr_sum == target_sum) || 
                has_path_sum_helper(curr_node->left, curr_sum, target_sum) ||
                has_path_sum_helper(curr_node->right, curr_sum, target_sum);
    }

public:
    static bool hasPathSum(TreeNode* root, int targetSum) {
        const int curr_sum = 0;
        return has_path_sum_helper(root, curr_sum, targetSum);
    }
};
