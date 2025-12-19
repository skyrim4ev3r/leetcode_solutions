/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node, unordered_map<int, Node*>& map) {
        auto find = map.find(node->val);
        if (find != map.end()) {
            return find->second;
        }

        Node* new_node = new Node(node->val);
        new_node->neighbors.reserve(node->neighbors.size());
        map[node->val] = new_node;

        for (const auto n : node->neighbors) {
            new_node->neighbors.push_back(dfs(n, map));
        }

        return new_node;
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<int, Node*> map;
        return dfs(node, map);
    }
};
