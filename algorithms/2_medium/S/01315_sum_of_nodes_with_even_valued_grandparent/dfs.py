# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr_node, is_grandpa_even, is_parent_even):
        if curr_node == None:
            return 0

        res = 0

        if is_grandpa_even:
            res += curr_node.val

        is_curr_node_even = ((curr_node.val % 2) == 0)
        res += self.dfs(curr_node.left, is_parent_even, is_curr_node_even)
        res += self.dfs(curr_node.right, is_parent_even, is_curr_node_even)

        return res

    def sumEvenGrandparent(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root, False, False)
