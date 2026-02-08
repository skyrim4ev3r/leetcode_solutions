/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
const countKDifference = (nums, k) => {
    let freqs = {};
    let count = 0;

    for (const num of nums) {
        const val1 = freqs[num - k];
        if (val1 != null) {
            count += val1;
        }

        const val2 = freqs[num + k];
        if (val2 != null) {
            count += val2;
        }

        freqs[num] = (freqs[num] || 0) + 1;
    }

    return count;
};
