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
    int dfs(TreeNode* curr, bool is_left_child) {
        if (curr == nullptr) {
            return 0;
        }

        int sum{0};

        if (is_left_child && curr->left == nullptr && curr->right == nullptr){
            sum += curr->val;
        }

        sum += dfs(curr->left, true);
        sum += dfs(curr->right, false);

        return  sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};
