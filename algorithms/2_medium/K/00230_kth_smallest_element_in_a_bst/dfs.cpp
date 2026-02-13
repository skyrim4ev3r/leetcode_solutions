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
    void dfs(TreeNode* curr, const int k, int &count, int& res) {
        if (curr == nullptr || count > k) {
            return;
        }

        dfs(curr->left, k, count, res);

        count += 1;

        if (count == k) {
            res = curr->val;
        }

        dfs(curr->right, k, count, res);
    }
public:
    int kthSmallest(TreeNode* root, const int k) {
        int res{ 0 };
        int count{ 0 };

        dfs(root, k, count, res);

        return res;
    }
};
