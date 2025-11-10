# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None

        odd_head = ListNode(0)
        even_head = ListNode(0)

        odd_current = odd_head
        even_current = even_head
        is_odd = True

        curr = head
        while curr != None:
            temp = curr
            curr = curr.next
            temp.next = None

            if is_odd:
                odd_current.next = temp
                odd_current = temp
            else:
                even_current.next = temp
                even_current = temp

            is_odd = not is_odd

        odd_current.next = even_head.next
        return odd_head.next
