class Solution {
    void helper(TreeNode* curr_node, TreeNode* &prev) {
        if (curr_node == nullptr) {
            return;
        }

        TreeNode* left = curr_node->left;
        TreeNode* right = curr_node->right;

        curr_node->left = nullptr;
        curr_node->right = nullptr;

        if (prev != nullptr) {
            prev->right = curr_node;
        }

        prev = curr_node;

        helper(left, prev);
        helper(right, prev);
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* prev{nullptr};
        helper(root, prev);
    }
};
