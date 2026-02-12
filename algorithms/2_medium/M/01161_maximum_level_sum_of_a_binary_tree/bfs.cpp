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
    int maxLevelSum(TreeNode* root) {
        int level{ 1 };
        int max_sum{ numeric_limits<int>::min() };
        int max_sum_level = 1;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            const size_t curr_len{ q.size() };
            int curr_sum{ 0 };

            for (size_t c{ 0 }; c < curr_len; ++c) {
                auto node{ q.front() };
                q.pop();

                curr_sum += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                max_sum_level = level;
            }

            level += 1;
        }

        return max_sum_level;
    }
};
