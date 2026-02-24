const dfs = (curr_node, sum, curr_bin) => {
    if (curr_node === null) {
        return;
    }

    curr_bin.val = curr_bin.val << 1;
    curr_bin.val |= curr_node.val;

    if (curr_node.left === null && curr_node.right === null) {
        sum.val += curr_bin.val;
    }

    dfs(curr_node.left, sum, curr_bin);
    dfs(curr_node.right, sum, curr_bin);

    curr_bin.val = curr_bin.val >> 1;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
const sumRootToLeaf = (root) => {
    const sum = { val: 0};
    const curr = { val: 0};

    dfs(root, sum, curr);

    return sum.val;
};
