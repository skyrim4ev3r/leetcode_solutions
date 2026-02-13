# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def calc_len(self, curr: Optional[ListNode]) -> int:
        n = 0
        while curr != None:
            n += 1
            curr = curr.next
        return n

    def divide_list_and_make_tree(
        self,
        curr: Optional[ListNode],
        n: int,
    ) -> (Optional[TreeNode], Optional[ListNode]):
        if n == 0:
            return (None, curr)

        mid_index = n // 2
        left_len = mid_index
        right_len = n - 1 - mid_index

        (left_tree, mid_node) = self.divide_list_and_make_tree(curr, left_len)
        (right_tree, next_node) = self.divide_list_and_make_tree(mid_node.next,right_len)

        new_node = TreeNode(mid_node.val)
        new_node.left = left_tree
        new_node.right = right_tree

        return (new_node, next_node)

    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        n = self.calc_len(head)
        (result, _) = self.divide_list_and_make_tree(head, n)

        return result
