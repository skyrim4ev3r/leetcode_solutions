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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        queue<TreeNode*> q {};
        q.push(root);
        int curr_level {1};

        while (!q.empty()) {
            if (curr_level == depth - 1) {
                while (!q.empty()) {
                    TreeNode* old_node {q.front()};
                    q.pop();

                    TreeNode* node_l = new TreeNode(val);
                    node_l->left = old_node->left;
                    old_node->left = node_l;

                    TreeNode* node_r = new TreeNode(val);
                    node_r->right = old_node->right;
                    old_node->right = node_r;
                }

                break;
            }

            const size_t curr_len {q.size()};

            for (size_t i {0}; i < curr_len; ++i) {
                TreeNode* old_node {q.front()};
                q.pop();

                if (old_node->left != nullptr) {
                    q.push(old_node->left);
                }

                if (old_node->right != nullptr) {
                    q.push(old_node->right);
                }
            }

            curr_level += 1;
        }

        return root;
    }
};
