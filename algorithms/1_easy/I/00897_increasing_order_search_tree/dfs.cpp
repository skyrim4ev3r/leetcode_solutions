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
    void dfs(TreeNode* curr_node, TreeNode* & prev) {
        if (curr_node == nullptr) {
            return;
        }

        dfs(curr_node->left, prev);

        prev->right = curr_node;
        prev = curr_node;
        curr_node->left = nullptr;
        TreeNode* right = curr_node->right;
        curr_node->right = nullptr;

        dfs(right, prev);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy{new TreeNode(-1)};
        TreeNode* prev{dummy};
        dfs(root, prev);

        TreeNode* new_root = dummy->right;
        delete dummy;
        return new_root;
    }
};
