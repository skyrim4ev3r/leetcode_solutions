"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

from collections import deque

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root == None:
            return None

        q = deque()
        q.append(root)

        while q:
            curr_len = len(q)

            for i in range(curr_len):
                node = q.popleft()

                if i < curr_len - 1:
                    node.next = q[0]
                else:
                    node.next = None

                if node.left != None:
                    q.append(node.left)

                if node.right != None:
                    q.append(node.right)

        return root
