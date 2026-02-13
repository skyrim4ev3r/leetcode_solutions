/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    static inline size_t calc_len(ListNode* curr) {
        size_t len{ 0 };

        while (curr != nullptr) {
            len += 1;
            curr = curr->next;
        }

        return len;
    }

    static pair<TreeNode*, ListNode*> divide_list_and_make_tree(ListNode* curr, size_t len){
        if (len == 0) {
            return {nullptr, curr};
        }

        const size_t mid_index{ len / 2 };
        const size_t left_len{ mid_index };
        const size_t right_len{ len - 1 - mid_index };

        const auto [left_tree, mid_node] = divide_list_and_make_tree(curr, left_len);
        const auto [right_tree, next_node] = divide_list_and_make_tree(mid_node->next,right_len);

        TreeNode* new_node{ new TreeNode(mid_node->val) };
        new_node->left = left_tree;
        new_node->right = right_tree;

        return {new_node, next_node};
    }
public:
    static TreeNode* sortedListToBST(ListNode* head) {
        const size_t len{ calc_len(head) };

        return divide_list_and_make_tree(head, len).first;
    }
};
