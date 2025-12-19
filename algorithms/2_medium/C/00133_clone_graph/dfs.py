"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def dfs(self, node, hashmap):
        find = hashmap.get(node.val)
        if find != None:
            return find

        new_node = Node(node.val)
        hashmap[node.val] = new_node

        for n in node.neighbors:
            new_node.neighbors.append(self.dfs(n, hashmap))

        return new_node

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node == None:
            return None

        hashmap = {}
        return self.dfs(node, hashmap)
