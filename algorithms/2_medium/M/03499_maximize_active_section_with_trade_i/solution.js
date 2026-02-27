/**
 * @param {string} s
 * @return {number}
 */
const maxActiveSectionsAfterTrade = (s) => {
    const len = s.length;
    let total_ones = 0;
    let prev_zeros = 0;
    let curr_zeros = 0;
    let max = 0;

    for (let i = 0; i < len; ++i) {
        switch (s[i]) {
            case '0':
                curr_zeros += 1;
                if (prev_zeros > 0) {
                    max = Math.max(max, prev_zeros + curr_zeros);
                }
                break;
            case '1':
                if (i > 0 && s[i - 1] === '0') {
                    prev_zeros = curr_zeros;
                    curr_zeros = 0;
                }
                total_ones += 1;
                break;
            default:
                break;
        }
    }

    return max + total_ones;
};
