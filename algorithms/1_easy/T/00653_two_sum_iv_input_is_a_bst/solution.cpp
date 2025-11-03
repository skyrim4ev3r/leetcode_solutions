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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set{};
        stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {

            TreeNode* curr_node = stack.top();
            stack.pop();

            if (set.contains(k - curr_node->val)) {
                return true;
            }

            set.insert(curr_node->val);

            if (curr_node->right != nullptr) {
                stack.push(curr_node->right);
            }

            if (curr_node->left != nullptr) {
                stack.push(curr_node->left);
            }
        }

        return false;
    }
};
