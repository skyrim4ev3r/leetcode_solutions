class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* res_dummy{new ListNode(0)};
        ListNode* res_prev{res_dummy};
        int offset{0};

        while (l1 != nullptr || l2 != nullptr) {

            int num{0};
            if (l1 != nullptr) {
                num += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                num += l2->val;
                l2 = l2->next;
            }

            num += offset;
            offset = 0;
            if (num >= 10) {
                offset = 1;
                num -= 10;
            } 

            ListNode* new_node = new ListNode(num);
            res_prev->next = new_node;
            res_prev = new_node;
        }

        if (offset > 0) {
            ListNode* new_node = new ListNode(offset);
            res_prev->next = new_node;
        }

        ListNode* res_head = res_dummy->next;
        delete res_dummy;
        return res_head;
    }
};
