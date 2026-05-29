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
    bool dfs(TreeNode* curr_node, int64_t min_val, int64_t max_val) {
        if (curr_node == nullptr) {
            return true;
        }

        return curr_node->val > min_val && curr_node->val < max_val &&
               dfs(curr_node->left, min_val, curr_node->val) &&
               dfs(curr_node->right, curr_node->val, max_val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, numeric_limits<int64_t>::min() ,numeric_limits<int64_t>::max());
    }
};
