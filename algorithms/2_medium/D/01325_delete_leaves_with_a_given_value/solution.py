# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def clean_up_leaves(self, curr_node, target):
        if curr_node == None:
            return None

        curr_node.left = self.clean_up_leaves(curr_node.left, target)
        curr_node.right = self.clean_up_leaves(curr_node.right, target)

        if curr_node.val == target and curr_node.left == None and curr_node.right == None:
            return None

        return curr_node

    def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
        return self.clean_up_leaves(root, target)
