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
    void inorder_traversal_helper(vector<int> &res,TreeNode* curr_node){

        if (curr_node == nullptr) {
            return;
        }

        inorder_traversal_helper(res, curr_node->left);

        res.push_back(curr_node->val);

        inorder_traversal_helper(res, curr_node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res{};

        inorder_traversal_helper(res, root);

        return res;
    }
};
