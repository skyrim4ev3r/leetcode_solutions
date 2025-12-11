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
    void dfs(TreeNode* curr_node, int curr_row, int& selected_row, int& selected_left_val) {
        if (curr_node == nullptr) {
            return;
        }

        if (curr_row > selected_row) {
            selected_row = curr_row;
            selected_left_val = curr_node->val;
        }

        dfs(curr_node->left, curr_row + 1, selected_row, selected_left_val);
        dfs(curr_node->right, curr_row + 1, selected_row, selected_left_val);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int selected_row{-1};
        int selected_left_val{-1};

        dfs(root, 0, selected_row, selected_left_val);

        return selected_left_val;
    }
};
