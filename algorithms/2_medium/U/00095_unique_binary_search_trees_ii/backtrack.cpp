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
    static TreeNode* dfs_copy_tree(TreeNode* original_node) {
        if (original_node == nullptr) {
            return nullptr;
        }

        TreeNode* new_node = new TreeNode(original_node->val);

        new_node->left = dfs_copy_tree(original_node->left);
        new_node->right = dfs_copy_tree(original_node->right);

        return new_node;
    }

    static vector<TreeNode*> backtrack_generate_trees(int left, int right) {
        if (left > right) {
            return vector<TreeNode*>{nullptr};
        }

        vector<TreeNode*> res{};

        for (int i{ left }; i <= right; ++i) {
            const auto all_right{ backtrack_generate_trees(i + 1, right) };
            const auto all_left{ backtrack_generate_trees(left, i - 1) };

            for (const auto& ar : all_right) {
                for (const auto& al : all_left) {
                    TreeNode* node = new TreeNode(i);
                    node->left = dfs_copy_tree(al);
                    node->right = dfs_copy_tree(ar);
                    res.push_back(node);
                }
            }
        }

        return res;
    }
public:
    static vector<TreeNode*> generateTrees(int n) {
        return backtrack_generate_trees(1, n);
    }
};
