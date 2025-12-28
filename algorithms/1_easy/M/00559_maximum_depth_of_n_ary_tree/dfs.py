"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def dfs(self, curr, curr_depth):
        self.max_depth = max(self.max_depth, curr_depth)

        for child in curr.children:
            self.dfs(child, curr_depth + 1)

    def maxDepth(self, root: 'Node') -> int:
        if root == None:
            return 0

        self.max_depth = 0
        self.dfs(root, 1)

        return self.max_depth
