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
    int dfs(TreeNode* curr_node, int max_val) {
        if (curr_node == nullptr) {
            return 0;
        }

        int sum{0};

        if (max_val <= curr_node->val) {
            sum = 1;
            max_val = curr_node->val;
        }

        sum += dfs(curr_node->left, max_val);
        sum += dfs(curr_node->right, max_val);

        return sum;
    }
public:
    int goodNodes(TreeNode* root) {
        int max_val{numeric_limits<int>::min()};
        return dfs(root, max_val);
    }
};
