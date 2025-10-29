"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def dfs(self, curr, res):
        for child in curr.children:
            self.dfs(child, res)
        res.append(curr.val)

    def postorder(self, root: 'Node') -> List[int]:
        if root == None:
            return
        res = []
        self.dfs(root, res)
        return res
