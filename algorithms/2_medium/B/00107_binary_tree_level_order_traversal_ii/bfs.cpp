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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> res;

        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> queue;

        queue.push(root);

        while (!queue.empty()) {
            const size_t len{queue.size()};
            vector<int> temp;

            for (size_t i{0}; i < len; ++i) {
                TreeNode* node{queue.front()};
                queue.pop();

                temp.push_back(node->val);

                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }

            res.push_back(temp);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
