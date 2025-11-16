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
    void dfs(TreeNode* curr_node, int &min1, int &min2) {
        if (curr_node == nullptr) {
            return;
        }

        if (min1 == -1 || curr_node->val < min1) {
            min2 = min1;
            min1 = curr_node->val;
        } else if (curr_node->val != min1) {
            if (min2 == -1) {
                min2 = curr_node->val;
            } else {
                min2 = min(min2, curr_node->val);
            }
        }

        dfs(curr_node->left, min1, min2);
        dfs(curr_node->right, min1, min2);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        int min1{-1};
        int min2{-1};

        dfs(root, min1, min2);

        return min2;
    }
};
