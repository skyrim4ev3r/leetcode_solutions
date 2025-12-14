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

        res.append(curr.val)
        self.dfs(curr.left, res)
        self.dfs(curr.right, res)

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        self.dfs(root, res)

        return res
