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
 * @return {string[]}
 */
const dfs = (curr, res, temp) => {
    if (curr == null) {
        return;
    }

    temp.push(curr.val.toString());

    if (curr.left == null && curr.right == null) {
        res.push(temp.join("->"));
    } else {
        dfs(curr.left, res, temp);
        dfs(curr.right, res, temp);
    }

    temp.pop();
};

const binaryTreePaths = (root) => {
    const res = [];
    const temp = [];

    dfs(root, res, temp);

    return res;
};
