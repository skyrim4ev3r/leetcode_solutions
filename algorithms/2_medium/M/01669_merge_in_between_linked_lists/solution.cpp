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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        dummy->next = list1;

        ListNode* prev_a = dummy;
        for (int i{0}; i < a; ++i) {
            prev_a = prev_a->next;
        }

        ListNode* node_a = prev_a->next;
        ListNode* node_b = node_a;
        for (int i{a}; i < b; ++i) {
            node_b = node_b->next;
        }

        prev_a->next = list2;
        ListNode* last_node_list2 = prev_a;
        while (last_node_list2->next != nullptr) {
            last_node_list2 = last_node_list2->next;
        }

        last_node_list2->next = node_b->next;
        node_b->next = nullptr;

        ListNode* head = dummy->next;
        delete dummy;

        while (node_a != nullptr) {
            ListNode* tmp = node_a;
            node_a = node_a->next;
            delete tmp;
        }

        return head;
    }
};
