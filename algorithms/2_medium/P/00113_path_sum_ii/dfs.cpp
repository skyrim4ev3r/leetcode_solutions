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
    void dfs(
        vector<vector<int>> &res,
        vector<int> &temp,
        TreeNode* curr,
        int target_sum,
        int curr_sum
    ) {
        if (curr == nullptr) {
            return;
        }

        curr_sum += curr->val;
        temp.push_back(curr->val);
        if (curr->left == nullptr && curr->right == nullptr) {
            if (curr_sum == target_sum) {
                res.push_back(temp);
            }
        }

        dfs(res, temp, curr->left, target_sum, curr_sum);
        dfs(res, temp, curr->right, target_sum, curr_sum);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res{};
        vector<int> temp{};
        dfs(res, temp, root, targetSum, 0);

        return res;
    }
};
