# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        res_head = None
        res_curr = None

        curr = head.next
        tota_sum = 0

        while curr != None:
            if curr.val != 0:
                tota_sum += curr.val
            else:
                new_node = ListNode(tota_sum)
                tota_sum = 0
                if res_head == None:
                    res_head = new_node
                    res_curr = res_head
                else:
                    res_curr.next = new_node
                    res_curr = res_curr.next

            curr = curr.next

        return res_head
