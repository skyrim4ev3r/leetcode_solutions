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
    void zig_zag_helper_search(TreeNode* curr, int curr_zig_zag_len, bool should_call_left, int &max_zig_zag_len) {
        if (curr == nullptr) {
            return;
        }

        max_zig_zag_len = std::max(max_zig_zag_len, curr_zig_zag_len);

        if (should_call_left) {
            zig_zag_helper_search(curr->left, curr_zig_zag_len + 1, !should_call_left, max_zig_zag_len);
            zig_zag_helper_search(curr->right, 1, true, max_zig_zag_len);
        } else {
            zig_zag_helper_search(curr->left, 1, false, max_zig_zag_len);
            zig_zag_helper_search(curr->right, curr_zig_zag_len + 1, !should_call_left, max_zig_zag_len);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int max_zig_zag_len {0};
        zig_zag_helper_search(root, 0, false, max_zig_zag_len);
        return max_zig_zag_len;
    }
};
