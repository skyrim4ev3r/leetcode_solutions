class Solution:
    def dfs(self, curr_node, res):
        if curr_node == None:
            return

        res.append(str(curr_node.val))

        if curr_node.left != None or curr_node.right != None:
            res.append('(')
            self.dfs(curr_node.left, res)
            res.append(')')
            if curr_node.right != None:
                res.append('(')
                self.dfs(curr_node.right, res)
                res.append(')')

    def tree2str(self, root: Optional[TreeNode]) -> str:
        res = []
        self.dfs(root, res)

        return "".join(res)
