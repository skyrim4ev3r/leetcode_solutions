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
    void dfs(TreeNode* curr_node, int &max_level, int curr_level) {

        if (curr_node == nullptr) {
            return ;
        }

        max_level = std::max(max_level, curr_level);

        dfs(curr_node->left, max_level, curr_level + 1);
        dfs(curr_node->right, max_level, curr_level + 1);
    }
public:
    int maxDepth(TreeNode* root) {
        int max_level{0};

        dfs(root, max_level, 1);

        return max_level;
    }
};
