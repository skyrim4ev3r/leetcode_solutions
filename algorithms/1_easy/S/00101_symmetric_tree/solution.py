# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def is_symmetric_helper(self, p, q):
        if p == None and q == None:
            return True

        if p == None or q == None or p.val != q.val:
            return False

        return self.is_symmetric_helper(p.left, q.right) and self. is_symmetric_helper(p.right, q.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
         return self.is_symmetric_helper(root.left, root.right)
