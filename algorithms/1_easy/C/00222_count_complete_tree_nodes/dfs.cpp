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
    int dfs_count_nodes(TreeNode* curr_node) {
        if (curr_node == nullptr) {
            return 0;
        }

        return 1 + dfs_count_nodes(curr_node->left) + dfs_count_nodes(curr_node->right);
    }
public:
    int countNodes(TreeNode* root) {
        return dfs_count_nodes(root);
    }
};
