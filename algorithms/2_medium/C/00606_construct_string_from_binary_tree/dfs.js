const dfs = (curr_node, res) => {
    if (curr_node === null) {
        return;
    }

    res.push(curr_node.val);

    if (curr_node.left != null || curr_node.right != null) {
        res.push('(');
        dfs(curr_node.left, res);
        res.push(')');
        if (curr_node.right != null) {
            res.push('(');
            dfs(curr_node.right, res);
            res.push(')');
        }
    }
}
/**
 * @param {TreeNode} root
 * @return {string}
 */
const tree2str = (root) => {
    const res = [];
    dfs(root, res);

    return res.join("");
};
