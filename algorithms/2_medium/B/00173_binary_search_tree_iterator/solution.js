/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
class BSTIterator {

    /**
    * @param {TreeNode} root
    */
    constructor(root) {
        this.stack = [];
        this.push_node_and_all_left_childs(root)
    }

    push_node_and_all_left_childs(curr) {
        while (curr != null) {
            this.stack.push(curr);
            curr = curr.left;
        }
    }

    /**
    * @return {number}
    */
    next() {
        const curr = this.stack.pop();
        this.push_node_and_all_left_childs(curr.right);
        return curr.val;
    }

    /**
    * @return {boolean}
    */
    hasNext() {
        return this.stack.length != 0;
    }
}
