/**
 * @param {string} s
 * @param {number} k
 * @return {boolean}
 */
const hasAllCodes = (s, k) => {
    const seen = new Set();
    const len = s.length;

    for (let i = 0; i <= len - k; ++i) {
        seen.add(parseInt(s.substr(i, k), 2));
    }

    return seen.size === Math.pow(2, k);
};
