/**
 * @param {string} s
 * @return {number}
 */
const minimumDeletions = (s) => {
    let res = 0;
    let b_count = 0;

    for (const ch of s) {
        if (ch === 'b') {
            b_count += 1;
        } else if (b_count > 0) {
            res += 1;
            b_count -= 1;
        }
    }

    return res;
};
