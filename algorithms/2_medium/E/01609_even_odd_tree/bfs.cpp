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
    bool isEvenOddTree(TreeNode* root) {
        int curr_level{ 0 };
        queue<TreeNode*> q{};
        q.push(root);

        while (!q.empty()) {
            const size_t curr_len{ q.size() };
            int prev_val{
                (curr_level & 1) == 1 ? numeric_limits<int>::max() : numeric_limits<int>::min()
            };

            for (size_t _i{ 0 }; _i < curr_len; _i += 1) {
                auto node = q.front();
                q.pop();

                if ((curr_level & 1) == (node->val & 1)) {
                    return false;
                }

                if ((curr_level & 1) == 0) {
                    if (prev_val >= node->val) {
                        return false;
                    }
                } else {
                    if (prev_val <= node->val) {
                        return false;
                    }
                }

                prev_val = node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            curr_level += 1;
        }

        return true;
    }
};
