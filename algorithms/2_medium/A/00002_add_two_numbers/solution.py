class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        res_dummy = ListNode(0)
        res_prev = res_dummy
        offset = 0

        while l1 != None or l2 != None:

            num = 0
            if l1 != None:
                num += l1.val
                l1 = l1.next

            if l2 != None:
                num += l2.val
                l2 = l2.next

            num += offset
            offset = 0
            if num >= 10:
                offset = 1
                num -= 10

            new_node = ListNode(num)
            res_prev.next = new_node
            res_prev = new_node
        
        if offset > 0:
            new_node = ListNode(offset)
            res_prev.next = new_node

        return res_dummy.next
