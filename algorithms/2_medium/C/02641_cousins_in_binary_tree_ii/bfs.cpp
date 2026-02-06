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
    TreeNode* replaceValueInTree(TreeNode* root) {
        deque<pair<TreeNode*, int>> q{};
        q.push_back({ root, 0 });

        while (!q.empty()) {
            const size_t len{ q.size() };
            int level_sum{ 0 };

            for (const auto& [node, _] : q) {
                level_sum += node->val;
            }

            for (size_t count{ 0 }; count < len; ++count) {
                const auto [node, bruh_sum] = q.front();
                q.pop_front();
                const int curr_val{ node->val };
                node->val = level_sum - curr_val - bruh_sum;
                const int right_val{ node->right == nullptr ? 0 : node->right->val };
                const int left_val{ node->left == nullptr ? 0 : node->left->val };

                if (node->right != nullptr) {
                    q.push_back({ node->right, left_val });
                }

                if (node->left != nullptr) {
                    q.push_back({ node->left, right_val });
                }
            }
        }

        return root;
    }
};
