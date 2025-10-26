INT_MIN = -sys.maxsize - 1

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        stack_a = []
        stack_b = []

        stack_a.append(root)
        max_level = 1
        curr_level = 1
        max_level_sum = INT_MIN

        while stack_a:
            curr_level_sum = 0

            while stack_a:
                node = stack_a.pop()

                if node.left != None:
                    stack_b.append(node.left)

                if node.right != None:
                    stack_b.append(node.right)

                curr_level_sum +=  node.val

            if curr_level_sum > max_level_sum:
                max_level_sum = curr_level_sum
                max_level = curr_level

            stack_a = stack_b
            stack_b = []
            curr_level += 1

        return max_level
