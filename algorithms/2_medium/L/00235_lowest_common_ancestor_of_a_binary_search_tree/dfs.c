/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static struct TreeNode* dfs(struct TreeNode* curr, struct TreeNode* p, struct TreeNode* q)
{
    if (curr == NULL || curr == p || curr == q) {
        return curr;
    }

    struct TreeNode* left = dfs(curr->left, p, q);
    struct TreeNode* right = dfs(curr->right, p, q);

    if (left != NULL && right != NULL) {
        return curr;
    }

    return left == NULL ? right : left;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    assert(p != NULL && q != NULL && root != NULL && p->val != q->val);
    struct TreeNode* res = dfs(root, p, q);
    assert(res != NULL);
    return res;
}
