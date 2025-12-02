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

        self.curr_bin = self.curr_bin << 1
        self.curr_bin |= curr_node.val

        if curr_node.left == None and curr_node.right == None:
            self.sum += self.curr_bin
        else:
            self.dfs(curr_node.left)
            self.dfs(curr_node.right)

        self.curr_bin = self.curr_bin >> 1

    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        self.sum = 0
        self.curr_bin = 0

        self.dfs(root)

        return self.sum
