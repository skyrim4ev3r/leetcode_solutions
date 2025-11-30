# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, curr_node, prev):
        if curr_node == None:
            return

        self.dfs(curr_node.left, prev)
        prev[0].right = curr_node
        prev[0] = curr_node
        curr_node.left = None
        right = curr_node.right
        curr_node.right = None
        self.dfs(right, prev)

    def increasingBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        dummy = TreeNode(-1)
        prev = [dummy]
        self.dfs(root, prev)

        return dummy.right
