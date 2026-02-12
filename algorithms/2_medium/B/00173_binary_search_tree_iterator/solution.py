# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    def push_node_and_all_left_childs(self, curr: Optional[TreeNode]):
        while curr != None:
            self.stack.append(curr)
            curr = curr.left

    def __init__(self, root: Optional[TreeNode]):
        self.stack = []
        self.push_node_and_all_left_childs(root)

    def next(self) -> int:
        curr = self.stack.pop()
        self.push_node_and_all_left_childs(curr.right)
        return curr.val

    def hasNext(self) -> bool:
        return len(self.stack) != 0
