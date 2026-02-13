/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

 /**
 * Depth-first search to find the k-th smallest element in a BST.
 * @param {TreeNode} curr - The current node during traversal.
 * @param {number} k - The k-th smallest position to find.
 * @param {{ val: number }} count - A mutable object to keep track of the count.
 * @param {{ val: number }} res - A mutable object to store the result.
 * @return {void}
 */
const dfs = (curr, k, count, res) => {
    if (curr === null || count.val > k) {
        return;
    }

    dfs(curr.left, k, count, res);

    count.val += 1;

    if (count.val === k) {
        res.val = curr.val;
    }

    dfs(curr.right, k, count, res);
}

/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    const res = { val: 0 };
    const count = { val: 0 };

    dfs(root, k, count, res);

    return res.val;
};
