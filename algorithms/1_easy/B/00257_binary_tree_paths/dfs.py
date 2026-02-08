# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr: Optional[TreeNode], res: List[str], temp: List[str]):
        if curr == None:
            return

        temp.append(str(curr.val))

        if curr.left == None and curr.right == None:
            res.append("->".join(temp))
        else:
            self.dfs(curr.left, res, temp)
            self.dfs(curr.right, res, temp)

        temp.pop()

    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        res = []
        temp = []

        self.dfs(root, res, temp)

        return res
