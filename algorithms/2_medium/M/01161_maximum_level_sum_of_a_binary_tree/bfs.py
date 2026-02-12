# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        level = 1
        max_sum = -sys.maxsize - 1
        max_sum_level = 1
        q = deque()
        q.append(root)

        while q:
            curr_len = len(q)
            curr_sum = 0

            for c in range(curr_len):
                node = q.popleft()

                curr_sum += node.val

                if node.left != None:
                    q.append(node.left)

                if node.right != None:
                    q.append(node.right)

            if curr_sum > max_sum:
                max_sum = curr_sum
                max_sum_level = level

            level += 1

        return max_sum_level
