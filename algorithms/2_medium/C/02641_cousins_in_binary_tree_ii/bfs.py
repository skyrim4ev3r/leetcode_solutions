# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        q = deque()
        q.append((root, 0))

        while q:
            n = len(q)
            level_sum = 0

            for (node, _) in q:
                level_sum += node.val

            for _ in range(n):
                (node, bruh_sum) = q.popleft()
                curr_val = node.val
                node.val = level_sum - curr_val - bruh_sum
                right_val = 0 if node.right == None else node.right.val
                left_val = 0 if node.left == None else node.left.val

                if node.right != None:
                    q.append((node.right, left_val))
                if node.left != None:
                    q.append((node.left, right_val))

        return root
