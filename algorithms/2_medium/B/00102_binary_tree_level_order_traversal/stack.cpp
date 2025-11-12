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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res{};

        if (root == nullptr) {
            return res;
        }

        vector<TreeNode*> current_level{};
        vector<TreeNode*> next_level{};

        current_level.push_back(root);

        while (!current_level.empty()) {
            vector<int> temp;

            for (TreeNode* node : current_level) {
                temp.push_back(node->val);

                if (node->left != nullptr) {
                    next_level.push_back(node->left);
                }
                if (node->right != nullptr) {
                    next_level.push_back(node->right);
                }
            }

            res.emplace_back(std::move(temp));
            current_level = std::move(next_level);
        }

        return res;
    }
};
