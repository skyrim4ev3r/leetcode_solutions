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
    void dfs_insert(TreeNode& curr, int val) {
        if (curr.val > val) {
            if (curr.left != nullptr) {
                dfs_insert(*curr.left, val);
            } else {
                curr.left = new TreeNode(val);
            }
        } else if (curr.val < val) {
            if (curr.right != nullptr) {
                dfs_insert(*curr.right, val);
            } else {
                curr.right = new TreeNode(val);
            }
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        dfs_insert(*root, val);

        return root;
    }
};
