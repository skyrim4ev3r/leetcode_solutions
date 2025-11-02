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
    TreeNode* recursive(vector<int>& nums, size_t l, size_t r) {
        size_t mid{(l + r) / 2};
        TreeNode* new_node{new TreeNode(nums[mid])};

        if (l < mid) {
            new_node->left = recursive(nums, l, mid - 1);
        }

        if (mid < r) {
            new_node->right = recursive(nums, mid + 1, r);
        }

        return new_node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursive(nums, 0, nums.size() - 1);
    }
};
