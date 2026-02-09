/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
const dfs_tree_to_vec = (curr, res) => {
    if (curr == null) {
        return;
    }

    dfs_tree_to_vec(curr.left, res);
    res.push(curr);
    dfs_tree_to_vec(curr.right, res);
}

const dfs_vec_to_balance_tree = (res, left, right, len) => {
    if (left < 0 || right < 0 || right >= len || left >= len || left > right) {
        return null;
    }

    const mid = left + Math.floor((right - left) / 2);
    const node = res[mid];
    node.left = dfs_vec_to_balance_tree(res, left, mid - 1, len);
    node.right = dfs_vec_to_balance_tree(res, mid + 1, right, len);

    return node;
}

const balanceBST = (root) => {
    const res = [];
    dfs_tree_to_vec(root, res);

    const len = res.length;
    const left = 0;
    const right = len - 1;

    return dfs_vec_to_balance_tree(res, left, right, len);
};
