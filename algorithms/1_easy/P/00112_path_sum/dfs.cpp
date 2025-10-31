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
    bool dfs(TreeNode* curr_node, int curr_sum, int target_sum) {
        if (curr_node == nullptr) {
            return false;
        }

        curr_sum += curr_node->val;
        bool is_leaf = (curr_node->left == nullptr) && (curr_node->right == nullptr);

        return (is_leaf && curr_sum == target_sum) ||
                dfs(curr_node->left, curr_sum, target_sum) ||
                dfs(curr_node->right, curr_sum, target_sum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return  dfs(root, 0, targetSum);
    }
};
