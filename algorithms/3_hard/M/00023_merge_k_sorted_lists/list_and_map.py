# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        nums_map = {}
        for curr_node in lists:
            while curr_node != None:
                if curr_node.val in nums_map:
                    nums_map[curr_node.val] += 1
                else:
                    nums_map[curr_node.val] = 1

                curr_node = curr_node.next

        nums_list = sorted(list(nums_map.keys()), reverse=True)
        head = None
        for num in  nums_list:
            for i in range(nums_map[num]):
                new_node = ListNode(num)
                new_node.next = head
                head = new_node

        return head
