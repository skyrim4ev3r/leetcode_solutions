/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
const findTheWinner = (n, k) => {
    q = []

    for (let i = 1; i <= n; i += 1) {
        q.push(i);
    }

    while (q.length > 1) {
        const curr_len = q.length;
        const index_to_del = k % curr_len == 0 ? curr_len - 1 : k % curr_len - 1

        for (let i = 1; i <= index_to_del; i += 1) {
            q.push(q.shift());
        }

        q.shift();
    }

    return q.shift();
};
