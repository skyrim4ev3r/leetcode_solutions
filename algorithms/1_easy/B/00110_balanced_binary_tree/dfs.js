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
 * @return {boolean}
 */

const dfs_height = (curr, is_balanced) => {
    if (!is_balanced.val || curr == null) {
        return 0;
    }

    const left_height = dfs_height(curr.left, is_balanced);
    const right_height = dfs_height(curr.right, is_balanced);

    if ( Math.abs(left_height - right_height) > 1 ) {
        is_balanced.val = false;
    }

    return 1 + Math.max(left_height, right_height);
}

const isBalanced = (root) => {
    is_balanced = { val: true };

    dfs_height(root, is_balanced);

    return is_balanced.val;
};
