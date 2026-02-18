/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

const dfs = (curr) => {
    if (curr === null) {
        return [0, 0];
    }

    const [l_max1, l_max2] = dfs(curr.left);
    const [r_max1, r_max2] = dfs(curr.right);

    return [
        l_max2 + r_max2 + curr.val,
        Math.max(l_max1, l_max2) + Math.max(r_max1, r_max2)
    ];
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
const rob = (root) => {
    const res = dfs(root);

    return Math.max(res[0], res[1]);
};
