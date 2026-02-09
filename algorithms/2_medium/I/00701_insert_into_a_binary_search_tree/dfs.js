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
 * @param {number} val
 * @return {TreeNode}
 */
const dfs_insert = (curr, val) => {
    if (curr.val > val) {
        if (curr.left != null) {
            dfs_insert(curr.left, val);
        } else {
            curr.left = new TreeNode(val);
        }
    } else if (curr.val < val) {
        if (curr.right != null) {
            dfs_insert(curr.right, val);
        } else {
            curr.right = new TreeNode(val);
        }
    }
}

const insertIntoBST = (root, val) => {
    if (root == null) {
        return new TreeNode(val);
    }

    dfs_insert(root, val);

    return root;
};
