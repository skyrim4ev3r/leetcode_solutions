/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
const characterReplacement = (s, k) => {
    const len = s.length;
    let freqs = new Array(26).fill(0);
    let left = 0;
    let curr_max_freq = 0;
    let res = 0;

    for (let right = 0; right < len; right += 1) {
        let total = right - left + 1;
        freqs[s[right].charCodeAt(0) - 'A'.charCodeAt(0)] += 1;
        curr_max_freq = Math.max(curr_max_freq, freqs[s[right].charCodeAt(0) - 'A'.charCodeAt(0)]);

        if (total - curr_max_freq > k) {
            freqs[s[left].charCodeAt(0) - 'A'.charCodeAt(0)] -= 1;
            left += 1;
        } else {
            res = total;
        }
    }

    return res;
};
