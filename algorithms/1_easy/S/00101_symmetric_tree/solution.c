static bool is_symmetric_helper(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL || q == NULL || p->val != q->val) {
        return false;
    }

    return is_symmetric_helper(p->left, q->right) && is_symmetric_helper(p->right, q->left);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root)
{
    return is_symmetric_helper(root->left, root->right);
}
