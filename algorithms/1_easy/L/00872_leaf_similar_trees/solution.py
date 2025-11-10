# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def fill_leaf_vector(self, leaf_vector, curr):
        if curr == None:
            return

        self.fill_leaf_vector(leaf_vector, curr.left)
        self.fill_leaf_vector(leaf_vector, curr.right)

        if curr.left == None and curr.right == None:
            leaf_vector.append(curr.val)

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        leaf1 = []
        leaf2 = []

        self.fill_leaf_vector(leaf1, root1)
        self.fill_leaf_vector(leaf2, root2)

        return leaf1 == leaf2
