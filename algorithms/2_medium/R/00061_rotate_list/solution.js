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
 * @return {ListNode}
 */
const calc_len_and_shift_count = (head, k) => {
    let len = 0;
    let curr = head;

    while (curr != null) {
        len += 1;
        curr = curr.next;
    }

    const shift_count = (len === 0) ? 0 : (len - k % len) % len;

    return [len, shift_count];
};

const split_into_two_list = (head, shift_count) => {
    let curr = head;

    for (let i = 0; i < shift_count - 1; ++i) {
        curr = curr.next;
    }

    const head2 = curr.next;
    curr.next = null;

    return [head, head2];
};

const rotateRight = (head, k) => {
    const [len, shift_count] = calc_len_and_shift_count(head, k);

    if (len <= 1 || shift_count == 0) {
        return head;
    }

    let [h1, h2] = split_into_two_list(head, shift_count);
    let curr = h2;

    while (curr.next != null) {
        curr = curr.next;
    }

    curr.next = h1;

    return h2;
};
