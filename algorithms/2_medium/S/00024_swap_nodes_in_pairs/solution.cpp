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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy{new ListNode(0)};
        dummy->next = head;

        ListNode* prev{dummy};
        ListNode* curr_node{prev->next};

        while (curr_node != nullptr) {
            ListNode* next_node{curr_node->next};

            if (next_node == nullptr) {
                break;
            }

            prev->next = next_node;
            curr_node->next = next_node->next;
            next_node->next = curr_node;
            prev = curr_node;
            curr_node = curr_node->next;
        }

        ListNode* new_head{dummy->next};
        delete dummy;
        return new_head;
    }
};
