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
    void dfs(vector<int> &res, TreeNode* curr, size_t depth) {
        if (curr == nullptr) {
            return;
        }

        if (depth >= res.size()) {
            res.push_back(curr->val);
        } else {
            res[depth] = curr->val;
        }

        dfs(res, curr->left, depth + 1);
        dfs(res, curr->right, depth + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        dfs(res, root, 0);

        return res;
    }
};
