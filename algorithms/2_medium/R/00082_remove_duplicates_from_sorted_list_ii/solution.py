# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        while prev != None:
            curr = prev.next

            if curr != None and curr.next != None:
                if curr.val == curr.next.val:
                    val_to_del = curr.val

                    while curr != None and curr.val == val_to_del:
                        curr = curr.next

                    prev.next = curr
                else:
                    prev = curr
                    curr = curr.next
            else:
                break

        return dummy.next
