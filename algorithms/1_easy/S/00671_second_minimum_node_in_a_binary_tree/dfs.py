# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr_node):
        if curr_node == None:
            return

        if self.min1 == -1 or curr_node.val < self.min1:
            self.min2 = self.min1
            self.min1 = curr_node.val
        elif curr_node.val != self.min1:
            if self.min2 == -1:
                self.min2 = curr_node.val
            else:
                self.min2 = min(self.min2, curr_node.val)

        self.dfs(curr_node.left)
        self.dfs(curr_node.right)

    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        self.min1 = -1
        self.min2 = -1

        self.dfs(root)

        return self.min2
