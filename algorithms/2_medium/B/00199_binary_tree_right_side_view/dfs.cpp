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
    static void dfs(vector<int> &res, TreeNode* curr, const size_t depth) {
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
    static vector<int> rightSideView(TreeNode* root) {
        auto res = vector<int>();

        dfs(res, root, 0);

        return res;
    }
};
