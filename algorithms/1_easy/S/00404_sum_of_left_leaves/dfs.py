# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr, is_left_child):
        if curr == None:
            return 0

        s = 0

        if is_left_child and curr.left == None and curr.right == None:
            s += curr.val

        s += self.dfs(curr.left, True)
        s += self.dfs(curr.right, False)

        return  s

    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root, False)
