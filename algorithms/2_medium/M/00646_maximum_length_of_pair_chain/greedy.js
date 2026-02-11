/**
 * @param {number[][]} pairs
 * @return {number}
 */
const findLongestChain = (pairs) => {
    pairs.sort((a, b) => a[1] - b[1]);

    let curr_end = pairs[0][1];
    let count = 1;

    for (const p of pairs) {
        if (p[0] > curr_end) {
            curr_end = p[1];
            count += 1;
        }
    }

    return count;
};
