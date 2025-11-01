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
    TreeNode* clean_up_leaves(TreeNode* curr_node, int target) {
        if (curr_node == nullptr) {
            return nullptr;
        }

        curr_node->left = clean_up_leaves(curr_node->left, target);
        curr_node->right = clean_up_leaves(curr_node->right, target);

        if (curr_node->val == target && curr_node->left == nullptr && curr_node->right ==nullptr) {
            return nullptr;
        }

        return curr_node;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return clean_up_leaves(root, target);
    }
};
