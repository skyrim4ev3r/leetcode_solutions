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
 * @return {number}
 */
const dfs = (curr, parent_val, max_path) => {
    if (curr == null) {
        return 0;
    }

    const left_child_path = dfs(curr.left, curr.val, max_path);
    const right_child_path = dfs(curr.right, curr.val, max_path);
    max_path.value = Math.max(max_path.value, 1 + left_child_path + right_child_path);

    if (curr.val == parent_val) {
        return 1 + Math.max(left_child_path, right_child_path);
    } else {
        return 0;
    }
}

const longestUnivaluePath = (root) => {
    if (root == null) {
        return 0;
    }

    const max_path = { value: 0 };
    dfs(root, 0, max_path);
    const max_path_edges = max_path.value - 1;

    return max_path_edges;
};
