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
const maxLevelSum = (root) => {
    let level = 1;
    let max_sum = Number.MIN_SAFE_INTEGER;
    let max_sum_level = 1;
    const q = [];
    q.push(root);

    while (q.length > 0) {
        const curr_len = q.length;
        let curr_sum = 0;

        for (let c = 0; c < curr_len; ++c) {
            const node = q.shift();

            curr_sum += node.val;

            if (node.left != null) {
                q.push(node.left);
            }

            if (node.right != null) {
                q.push(node.right);
            }
        }

        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            max_sum_level = level;
        }

        level += 1;
    }

    return max_sum_level;
};
