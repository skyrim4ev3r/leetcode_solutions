/**
 * @param {number[]} nums
 * @return {number}
 */
const findLHS = (nums) => {
    const freqs = new Map();

    for (const num of nums) {
        freqs.set(num, (freqs.get(num) || 0) + 1)
    }

    let longest = 0;

    for (const [val, freq] of freqs) {
        const next_val = freqs.get(val + 1);
        if (next_val != null) {
            longest = Math.max(longest, freq + next_val);
        }

        const prev_val = freqs.get(val - 1);
        if (prev_val != null) {
            longest = Math.max(longest, freq + prev_val);
        }
    }

    return longest;
};
