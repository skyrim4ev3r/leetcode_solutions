/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        assert(p != nullptr && q != nullptr && root != nullptr && p->val != q->val);
        const int p_val = p->val;
        const int q_val = q->val;

        struct TreeNode* curr = root;

        while (true) {
            const int curr_val = curr->val;
            if (curr_val < p_val && curr_val < q_val) {
                curr = curr->right;
                assert(curr != nullptr);
            } else if (curr_val > p_val && curr_val > q_val) {
                curr = curr->left;
                assert(curr != nullptr);
            } else {
                break;
            }
        }

        return curr;
    }
};
