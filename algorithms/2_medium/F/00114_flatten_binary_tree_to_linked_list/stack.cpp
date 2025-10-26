class Solution {
public:
    void flatten(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        TreeNode* prev{nullptr};

        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();

            if (node->right != nullptr) {
                stack.push(node->right);
            }

            if (node->left != nullptr) {
                stack.push(node->left);
            }

            node->left = nullptr;
            node->right = nullptr;

            if (prev != nullptr) {
                prev->right = node;
            }

            prev = node;
        }
    }
};
