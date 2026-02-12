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
class BSTIterator {
    stack<TreeNode*> stack;

    void push_node_and_all_left_childs(TreeNode* curr) {
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        }
    }
public:
    BSTIterator(TreeNode* root) : stack{} {
        push_node_and_all_left_childs(root);
    }

    int next() {
        auto curr{ stack.top() };
        stack.pop();
        push_node_and_all_left_childs(curr->right);
        return curr->val;
    }

    bool hasNext() {
        return !stack.empty();
    }
};
