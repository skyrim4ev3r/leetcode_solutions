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
    int dfs(TreeNode* curr, const int parent_val, int& max_path) {
        if (curr == nullptr) {
            return 0;
        }

        const int left_child_path{ dfs(curr->left, curr->val, max_path) };
        const int right_child_path{ dfs(curr->right, curr->val, max_path) };
        max_path = std::max(max_path, 1 + left_child_path + right_child_path);

        if (curr->val == parent_val) {
            return 1 + std::max(left_child_path, right_child_path);
        } else {
            return 0;
        }
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int max_path{ 0 };
        dfs(root, 0, max_path);
        const int max_path_edges{ max_path - 1 };

        return max_path_edges;
    }
};
