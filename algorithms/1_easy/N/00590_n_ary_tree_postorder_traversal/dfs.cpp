/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void dfs(Node* curr, vector<int> &res) {
        if (curr == nullptr) {
            return;
        }

        for (Node* &child: curr->children) {
            dfs(child, res);
        }

        res.push_back(curr->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res{};
        dfs(root, res);
        return res;
    }
};
