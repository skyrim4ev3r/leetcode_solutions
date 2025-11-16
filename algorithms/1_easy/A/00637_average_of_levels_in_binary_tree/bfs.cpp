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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        vector<double> res{};

        while (!queue.empty()) {
            const size_t n{queue.size()};
            double sum{0};

            for (size_t i{0}; i < n; ++i) {
                auto curr{queue.front()};
                queue.pop();
                sum += curr->val;

                if (curr->left != nullptr) {
                    queue.push(curr->left);
                }
                if (curr->right != nullptr) {
                    queue.push(curr->right);
                }
            }

            res.push_back(sum / static_cast<double>(n));
        }

        return res;
    }
};
