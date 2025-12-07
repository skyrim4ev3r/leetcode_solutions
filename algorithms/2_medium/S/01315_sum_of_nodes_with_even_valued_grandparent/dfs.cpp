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
    int dfs(TreeNode* curr_node, bool is_grandpa_even, bool is_parent_even) {
        if (curr_node == nullptr) {
            return 0;
        }

        int sum = 0;

        if (is_grandpa_even) {
            sum += curr_node->val;
        }

        bool is_curr_node_even = ((curr_node->val % 2) == 0);
        sum += dfs(curr_node->left, is_parent_even, is_curr_node_even);
        sum += dfs(curr_node->right, is_parent_even, is_curr_node_even);

        return sum;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, false, false);
    }
};
