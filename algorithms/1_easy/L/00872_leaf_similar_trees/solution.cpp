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
    void fill_leaf_vector(vector<int> &leaf_vector, TreeNode* curr) {
        if (curr == nullptr) {
            return;
        }

        fill_leaf_vector(leaf_vector, curr->left);
        fill_leaf_vector(leaf_vector, curr->right);

        if (curr->left == nullptr && curr->right == nullptr) {
            leaf_vector.push_back(curr->val);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1{};
        vector<int> leaf2{};

        fill_leaf_vector(leaf1, root1);
        fill_leaf_vector(leaf2, root2);

        return leaf1 == leaf2;
    }
};
