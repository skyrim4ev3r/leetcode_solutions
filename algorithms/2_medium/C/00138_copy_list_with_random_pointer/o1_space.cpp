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

        Node* curr{ head };

        while (curr != nullptr) {
            Node* new_node{ new Node(curr->val) };
            new_node->next = curr->next;
            curr->next = new_node;
            curr = curr->next->next;
        }

        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        Node* res_dummy{ new Node(0) };
        Node* res_prev{ res_dummy };
        curr = head;
        while (curr != nullptr) {
            res_prev->next = curr->next;
            res_prev = curr->next;
            curr->next = res_prev->next;
            res_prev->next = nullptr;
            curr = curr->next;
        }

        Node* res{ res_dummy->next };
        delete res_dummy;
        return res;
    }
};
