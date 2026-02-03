# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        curr_level = 0
        q = deque()
        q.append(root)

        while q:
            curr_len = len(q)
            prev_val = sys.maxsize if (curr_level & 1) == 1 else -sys.maxsize - 1

            for _ in range(curr_len):
                node = q.popleft()

                if (curr_level & 1) == (node.val & 1):
                    return False

                if (curr_level & 1) == 0:
                    if prev_val >= node.val:
                        return False
                else:
                    if prev_val <= node.val:
                        return False

                prev_val = node.val

                if node.left != None:
                    q.append(node.left)

                if node.right != None:
                    q.append(node.right)

            curr_level += 1

        return True
