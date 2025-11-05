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
    int rangeSumBST_recursive(TreeNode* curr_node, int low, int high) {

         if (curr_node == nullptr) {
            return 0;
        }

        int sum{0};

        if (curr_node->val >= low && curr_node->val <= high) {
            sum += curr_node->val;
        }

        sum += rangeSumBST_recursive(curr_node->left, low, high);
        sum += rangeSumBST_recursive(curr_node->right, low, high);

        return sum;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {

        return rangeSumBST_recursive(root, low, high);
    }
};
