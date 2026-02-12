/**
 * @param {string} s
 * @return {number}
 */
const longestBalanced = (s) => {
    const len = s.length;
    let longest = 0;

    for (let i = 0; i < len; i += 1) {
        const freqs = new Array(26).fill(0);

        for (let j = i; j < len; j += 1) {
            const freq_index = (s[j].charCodeAt(0) - 'a'.charCodeAt(0));
            freqs[freq_index] += 1;
            let curr_freq = freqs[freq_index];

            if (freqs.every(freq => freq == 0 || freq == curr_freq)) {
                longest = Math.max(longest, j - i + 1);
            }
        }
    }

    return longest;
};
