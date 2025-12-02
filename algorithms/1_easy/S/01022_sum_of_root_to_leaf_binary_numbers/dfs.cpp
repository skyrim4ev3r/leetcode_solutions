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
    void dfs(TreeNode* curr_node, int& sum, int& curr_bin) {
        if (curr_node == nullptr) {
            return;
        }

        curr_bin = curr_bin << 1;
        curr_bin |= curr_node->val;

        if (curr_node->left == nullptr && curr_node->right == nullptr) {
            sum += curr_bin;
        } else {
            dfs(curr_node->left, sum, curr_bin);
            dfs(curr_node->right, sum, curr_bin);
        }

        curr_bin = curr_bin >> 1;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum{0};
        int curr_bin{0};

        dfs(root, sum, curr_bin);

        return sum;
    }
};
