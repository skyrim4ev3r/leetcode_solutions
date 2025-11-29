# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, curr_node, curr_node_cloned, target):
        if curr_node == None or self.res != None:
            return

        if curr_node == target:
            self.res = curr_node_cloned
            return

        self.dfs(curr_node.left, curr_node_cloned.left, target)
        self.dfs(curr_node.right, curr_node_cloned.right, target)

    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        self.res = None

        self.dfs(original, cloned, target)

        return self.res
