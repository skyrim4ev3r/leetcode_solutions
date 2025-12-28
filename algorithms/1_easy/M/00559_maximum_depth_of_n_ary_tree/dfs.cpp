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
    void dfs(Node* curr, int& max_depth, int curr_depth) {
        max_depth = std::max(max_depth, curr_depth);

        for (auto& child : curr->children) {
            dfs(child, max_depth, curr_depth + 1);
        }
    }
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int max_depth {0};
        dfs(root, max_depth, 1);

        return max_depth;
    }
};
