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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res{};
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q{};
        q.push(root);
        bool flip_flop{false};

        while (!q.empty()) {
            const size_t len{q.size()};
            vector<int> temp;
            temp.reserve(len);

            for (size_t i{0}; i < len; ++i) {
                auto node = q.front();
                q.pop();
                temp.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (flip_flop) {
                reverse(temp.begin(), temp.end());
            }

            res.emplace_back(temp);
            flip_flop = !flip_flop;
        }

        return res;
    }
};
