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
    void dfs(TreeNode* curr_node, int curr_level, int &max_level, int &sum) {
        if (curr_node == nullptr) {
            return;
        }

        if (curr_level > max_level) {
            max_level = curr_level;
            sum = curr_node->val;
        } else if (curr_level == max_level) {
            sum += curr_node->val;
        }

        dfs(curr_node->left, curr_level + 1, max_level, sum);
        dfs(curr_node->right, curr_level + 1, max_level, sum);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int max_level{-1};
        int sum{0};

        dfs(root, 0, max_level, sum);

        return sum;
    }
};
