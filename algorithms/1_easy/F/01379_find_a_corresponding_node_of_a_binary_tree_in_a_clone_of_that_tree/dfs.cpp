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
    void dfs(TreeNode* curr_node, TreeNode* curr_node_cloned, TreeNode* target, TreeNode* & res) {
        if (curr_node == nullptr || res != nullptr) {
            return;
        }

        if (curr_node == target) {
            res = curr_node_cloned;
            return;
        }

        dfs(curr_node->left, curr_node_cloned->left, target, res);
        dfs(curr_node->right, curr_node_cloned->right, target, res);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res = nullptr;

        dfs(original, cloned, target, res);

        return res;
    }
};
