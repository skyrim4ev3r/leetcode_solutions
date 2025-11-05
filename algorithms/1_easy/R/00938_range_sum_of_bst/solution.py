# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST_recursive(self, curr_node, low, high):
        if curr_node == None:
            return 0

        total_sum = 0

        if curr_node.val >= low and curr_node.val <= high:
            total_sum += curr_node.val

        total_sum += self.rangeSumBST_recursive(curr_node.left, low, high)
        total_sum += self.rangeSumBST_recursive(curr_node.right, low, high)

        return total_sum

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        return self.rangeSumBST_recursive(root, low, high)
