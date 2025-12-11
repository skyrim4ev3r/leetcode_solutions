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
    void dfs(
        TreeNode* curr_node,
        const size_t curr_row,
        vector<int>& max_rows
    ) {
        if (curr_node == nullptr) {
            return;
        }

        if (curr_row >= max_rows.size()) {
            max_rows.push_back(curr_node->val);
        } else {
            max_rows[curr_row] = std::max(max_rows[curr_row], curr_node->val);
        }

        dfs(curr_node->left, curr_row + 1, max_rows);
        dfs(curr_node->right, curr_row + 1, max_rows);
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> max_rows{};

        dfs(root, 0, max_rows);

        return max_rows;
    }
};
