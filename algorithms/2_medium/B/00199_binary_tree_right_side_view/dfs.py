# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, res, curr, depth):
        if curr == None:
            return

        if depth >= len(res):
            res.append(curr.val)
        else:
            res[depth] = curr.val

        self.dfs(res, curr.left, depth + 1)
        self.dfs(res, curr.right, depth + 1)

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        res = []

        self.dfs(res, root, 0)

        return res
