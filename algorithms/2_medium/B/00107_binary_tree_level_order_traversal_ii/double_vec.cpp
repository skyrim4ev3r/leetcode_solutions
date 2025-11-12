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

        vector<TreeNode*> v1, v2;

        v1.push_back(root);

        while (!v1.empty()) {

            vector<int> tmp;
            for (TreeNode* node: v1) {
                tmp.push_back(node->val);
            }
            res.push_back(tmp);

            for (TreeNode* node: v1) {
                if (node->left != nullptr) {
                    v2.push_back(node->left);
                }
                if (node->right != nullptr) {
                    v2.push_back(node->right);
                }
            }

            v1.clear();
            std::swap(v1, v2);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
