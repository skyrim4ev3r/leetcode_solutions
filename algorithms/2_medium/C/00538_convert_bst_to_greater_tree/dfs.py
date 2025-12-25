# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr: Optional[TreeNode]):
        if curr == None:
            return

        self.dfs(curr.right)
        curr.val += self.val
        self.val = curr.val
        self.dfs(curr.left)

    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.val = 0
        self.dfs(root)

        return root
