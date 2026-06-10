/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    assert(p != NULL && q != NULL && root != NULL && p->val != q->val);
    const int p_val = p->val;
    const int q_val = q->val;

    struct TreeNode* curr = root;

    while (true) {
        const int curr_val = curr->val;
        if (curr_val < p_val && curr_val < q_val) {
            curr = curr->right;
            assert(curr != NULL);
        } else if (curr_val > p_val && curr_val > q_val) {
            curr = curr->left;
            assert(curr != NULL);
        } else {
            break;
        }
    }

    return curr;
}
