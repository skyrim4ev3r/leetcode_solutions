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
    static void dfs(vector<vector<int>> &res, vector<int> &temp, TreeNode* curr_node, int target_sum, int prev_sum) {
        if (curr_node == nullptr) {
            return;
        }

        temp.push_back(curr_node->val);

        const bool is_leaf = (curr_node->left == nullptr) && (curr_node->right == nullptr);
        const int curr_sum = prev_sum + curr_node->val;

        if (is_leaf && curr_sum == target_sum) {
            res.push_back(temp);
        }

        dfs(res, temp, curr_node->left, target_sum, curr_sum);
        dfs(res, temp, curr_node->right, target_sum, curr_sum);

        temp.pop_back();
    }
public:
    static vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        auto res = vector<vector<int>>();
        auto temp = vector<int>();
        const int curr_sum = 0;

        dfs(res, temp, root, targetSum, curr_sum);

        return res;
    }
};
