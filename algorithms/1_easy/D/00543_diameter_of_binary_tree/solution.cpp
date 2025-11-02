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
    int diameter_of_binary_tree_helper(const TreeNode* curr_node, int &max_path) {

        if (curr_node == nullptr) {
            return 0;
        }

        int left_path_len = diameter_of_binary_tree_helper(curr_node->left, max_path);
        int right_path_len = diameter_of_binary_tree_helper(curr_node->right, max_path);

        int curr_node_path = 1 + left_path_len + right_path_len;

        max_path = std::max(max_path, curr_node_path);

        return 1 + std::max(left_path_len, right_path_len);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_path{INT_MIN};

        diameter_of_binary_tree_helper(root, max_path);

        // Subtract 1 because the diameter is defined as the number of edges,
        // which is one less than the number of nodes in the longest path.
        return max_path - 1;
    }
};
