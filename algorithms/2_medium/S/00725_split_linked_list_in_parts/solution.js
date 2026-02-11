/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode[]}
 */
const calc_len = (curr) => {
    let len = 0;
    while (curr != null) {
        curr = curr.next;
        len += 1;
    }
    return len;
}

const splitListToParts = (head, k) => {
    const len = calc_len(head);
    const seg_len = Math.floor(len / k);
    let extra = len % k;
    let curr = head;
    const dummy = new ListNode(0);
    res = new Array(k).fill(null);

    for (let i = 0; i < k; i += 1) {
        let prev = dummy;
        const target_len = seg_len + ((extra > 0) ? 1 : 0);

        if (extra > 0) {
            extra -= 1;
        }

        if (target_len === 0) {
            break;
        }

        for (let c = 0; c < target_len; c += 1) {
            prev.next = curr;
            prev = curr;
            curr = curr.next;
            prev.next = null;
        }

        res[i] = dummy.next;
        dummy.next = null;
    }

    return res;
};
