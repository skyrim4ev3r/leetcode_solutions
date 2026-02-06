/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> orig_to_copy{};
        Node* curr{ head };
        Node* res_dummy{ new Node(0) };
        Node* res_prev{ res_dummy };

        while (curr != nullptr) {
            Node* new_node{ new Node(curr->val) };
            res_prev->next = new_node;
            res_prev = new_node;

            orig_to_copy[curr] = new_node;
            curr = curr->next;
        }

        Node* res_curr{ res_dummy-> next };
        curr = head;
        while (curr != nullptr) {
            Node* random{ curr->random };

            if (random != nullptr) {
                Node* random_copy{ orig_to_copy[random] };
                res_curr->random = random_copy;
            }

            res_curr = res_curr->next;
            curr = curr->next;
        }

        Node* res{ res_dummy->next };
        delete res_dummy;
        return res;
    }
};
