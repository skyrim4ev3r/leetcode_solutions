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
    static int max_depth_helper(TreeNode* curr_node) {
        if (curr_node == nullptr) {
            return 0;
        }

        return 1 + std::max(max_depth_helper(curr_node->left), max_depth_helper(curr_node->right));
    }
public:
    static int maxDepth(TreeNode* root) {
        return max_depth_helper(root);
    }
};
