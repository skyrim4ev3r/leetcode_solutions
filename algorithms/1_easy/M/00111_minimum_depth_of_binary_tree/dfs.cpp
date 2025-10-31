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
    void dfs(const TreeNode* curr_node, const int curr_depth, int &min_depth) {
        if (curr_node == nullptr || curr_depth >= min_depth ) {
            return;
        }

        // Check if the current node is a leaf node
        if (curr_node->left == nullptr && curr_node->right==nullptr) {
            min_depth = min(min_depth, curr_depth);
        } else {
            // Only call dfs for children if the current node is not a leaf
            dfs(curr_node->left, curr_depth + 1, min_depth);
            dfs(curr_node->right, curr_depth + 1, min_depth);
        }
    }
public:
    int minDepth(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int min_depth{INT_MAX};

        dfs(root, 1, min_depth);

        return min_depth;
    }
};
