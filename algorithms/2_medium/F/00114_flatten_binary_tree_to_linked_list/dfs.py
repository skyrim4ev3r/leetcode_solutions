class Solution:
    def helper(self, curr_node, prev):
        if curr_node == None:
            return

        left = curr_node.left
        right = curr_node.right

        curr_node.left = None
        curr_node.right = None

        if prev[0] != None:
            prev[0].right = curr_node

        prev[0] = curr_node

        self.helper(left, prev)
        self.helper(right, prev)

    def flatten(self, root: Optional[TreeNode]) -> None:
        prev = [None]
        self.helper(root, prev)
