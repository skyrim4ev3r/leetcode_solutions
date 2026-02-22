/**
 * @param {number} n
 * @return {number}
 */
const binaryGap = (n) => {
    const BITS_COUNT = 32;
    let prev_valid_bit = [0, false];
    let max_dist = 0;

    for (let i = 0; i < BITS_COUNT; ++i) {
        const mask = 1 << i;

        if ((mask & n) != 0) {
            if (prev_valid_bit[1]) {
                max_dist = Math.max(max_dist, i - prev_valid_bit[0]);
            }

            prev_valid_bit = [i, true];
        }
    }

    return max_dist;
};
