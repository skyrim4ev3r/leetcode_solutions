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
    static struct TreeNode* arr_to_bst_helper(const vector<int>& nums, const ptrdiff_t left, const ptrdiff_t right) {
        if (left > right) {
            return nullptr;
        }

        const ptrdiff_t mid = left + (right - left) / 2;
        struct TreeNode* new_node = new TreeNode(nums[static_cast<size_t>(mid)]);
        new_node->left = arr_to_bst_helper(nums, left, mid - 1);
        new_node->right = arr_to_bst_helper(nums, mid + 1, right);
        return new_node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arr_to_bst_helper(nums, 0, nums.size() - 1);
    }
};
