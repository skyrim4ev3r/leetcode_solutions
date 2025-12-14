# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr, res):
        if curr == None:
            return

        self.dfs(curr.left, res)
        self.dfs(curr.right, res)
        res.append(curr.val)

    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        self.dfs(root, res)

        return res
