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
    void dfs_tree_to_vec(TreeNode* curr, vector<TreeNode*>& res) {
        if (curr == nullptr) {
            return;
        }

        dfs_tree_to_vec(curr->left, res);
        res.push_back(curr);
        dfs_tree_to_vec(curr->right, res);
    }

    TreeNode* dfs_vec_to_balance_tree(
        const vector<TreeNode*>& res,
        const size_t left,
        const size_t right,
        const size_t len
    ) {
        if (right >= len || left >= len || left > right) {
            return nullptr;
        }

        const size_t mid{ left + (right - left) / 2};
        TreeNode* node = res[mid];
        node->left = dfs_vec_to_balance_tree(res, left, mid - 1, len);
        node->right = dfs_vec_to_balance_tree(res, mid + 1, right, len);

        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> res{};
        dfs_tree_to_vec(root, res);

        const size_t len{ res.size() };
        const size_t left{ 0 };
        const size_t right{ len - 1};

        return dfs_vec_to_balance_tree(res, left, right, len);
    }
};
