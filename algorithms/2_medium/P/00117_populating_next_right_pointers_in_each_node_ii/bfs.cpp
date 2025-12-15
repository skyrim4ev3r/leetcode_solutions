/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            const size_t curr_len{q.size()};

            for (size_t i{0}; i < curr_len; ++i) {
                Node* node = q.front();
                q.pop();

                if (i < curr_len - 1) {
                    node->next = q.front();
                } else {
                    node->next = nullptr;
                }

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};
