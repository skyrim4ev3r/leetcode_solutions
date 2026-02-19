/**
 * @param {string} s
 * @return {number}
 */
const countBinarySubstrings = (s) => {
    const len = s.length;
    let curr_count = 1;
    let prev_count = 0;
    let res = 0;

    for (let i = 1; i < len; ++i) {
        if (s[i] != s[i - 1]) {
            res += Math.min(curr_count, prev_count);
            prev_count = curr_count;
            curr_count = 1;
        } else {
            curr_count += 1;
        }
    }

    res += Math.min(curr_count, prev_count);

    return res;
};
