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
    void invert_tree_helper(TreeNode* curr_node) {

        if (curr_node == nullptr) {
            return;
        }

        std::swap(curr_node->left, curr_node->right);

        invert_tree_helper(curr_node->left);
        invert_tree_helper(curr_node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {

        invert_tree_helper(root);

        return root;
    }
};
