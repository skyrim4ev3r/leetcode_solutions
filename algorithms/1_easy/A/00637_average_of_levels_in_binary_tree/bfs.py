# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        queue = deque()
        queue.append(root)
        res = []

        while queue:
            n = len(queue)
            total_sum = 0

            for i in range(n):
                node = queue.popleft()
                total_sum += node.val
                if node.left != None:
                    queue.append(node.left)
                if node.right != None:
                    queue.append(node.right)

            res.append(total_sum / n)

        return res
