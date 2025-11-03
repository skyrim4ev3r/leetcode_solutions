# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        num_set = set()
        stack = [root]

        while stack:
            curr_node = stack.pop()
            if k - curr_node.val in num_set:
                return True

            num_set.add(curr_node.val)

            if curr_node.right != None:
                stack.append(curr_node.right)

            if curr_node.left != None:
                stack.append(curr_node.left)

        return False
