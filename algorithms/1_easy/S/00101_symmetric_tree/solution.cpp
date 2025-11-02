class Solution {
    bool is_symmetric_helper(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }

        return is_symmetric_helper(p->left, q->right) && is_symmetric_helper(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return is_symmetric_helper(root->left, root->right);
    }
};
