/**
 * @param {string[]} words
 * @return {number}
 */
const longestPalindrome = (words) => {
    let freqs = [];
    for (let i = 0; i < 26; i += 1) {
        freqs[i] = new Array(26).fill(0);
    }

    let max_len = 0;

    for (const w of words) {
        const [i, j] = [w[0].charCodeAt(0) - 'a'.charCodeAt(0), w[1].charCodeAt(0) - 'a'.charCodeAt(0)];
        const [complement_i, complement_j] = [j, i];

        if (freqs[complement_i][complement_j] > 0) {
            // If complement_string exist then
            // Add both string & complement_string with total len of 4
            max_len += 4;
            freqs[complement_i][complement_j] -= 1;
        } else {
            freqs[i][j] += 1;
        }
    }

    // If self-palindrome strings are left,
    // Then we can use 1 of them as the middle part of final string.
    // Strings like: aa, bb, cc,..
    for (let i = 0; i < 26; i += 1) {
        if (freqs[i][i] > 0) {
            max_len += 2;
            break;
        }
    }

    return max_len;
};
