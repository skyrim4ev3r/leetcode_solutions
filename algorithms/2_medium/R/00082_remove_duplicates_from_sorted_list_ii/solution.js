/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const deleteDuplicates = (head) => {
    let dummy = new ListNode(0);
    dummy.next = head;
    let prev = dummy;

    while (prev != null) {
        let curr = prev.next;

        if (curr != null && curr.next != null) {
            if (curr.val === curr.next.val) {
                const val_to_del = curr.val;

                while (curr != null && curr.val === val_to_del) {
                    curr = curr.next;
                }

                prev.next = curr;
            } else {
                prev = curr;
                curr = curr.next;
            }
        } else {
            break;
        }
    }

    return dummy.next;
};
