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
        stack<TreeNode*> stack_a{};
        stack<TreeNode*> stack_b{};

        stack_a.push(root);
        int max_level{1};
        int curr_level{1};
        int max_level_sum{INT_MIN};

        while (!stack_a.empty()) {
            int curr_level_sum{0};

            while (!stack_a.empty()) {
                TreeNode* node{stack_a.top()};
                stack_a.pop();

                if (node->left != nullptr) {
                    stack_b.push(node->left);
                }

                if (node->right != nullptr) {
                    stack_b.push(node->right);
                }

                curr_level_sum +=  node->val;
            }

            if (curr_level_sum > max_level_sum) {
                max_level_sum = curr_level_sum;
                max_level = curr_level;
            }

            stack_a = move(stack_b);
            curr_level += 1;
        }

        return max_level;
    }
};
