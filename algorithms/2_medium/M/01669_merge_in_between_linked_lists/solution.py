# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.next = list1

        prev_a = dummy
        for i in range(a):
            prev_a = prev_a.next

        node_b = prev_a.next
        for i in range(a,b):
            node_b = node_b.next

        last_node_list2 = list2
        while last_node_list2.next != None:
            last_node_list2 = last_node_list2.next

        last_node_list2.next = node_b.next
        node_b.next = None
        prev_a.next = list2

        return dummy.next
