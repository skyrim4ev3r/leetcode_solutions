const calc_freqs = (s, freqs) => {
    for (const part of s.split(' ')) {
        freqs.set(part, (freqs.get(part) || 0) + 1);
    }
}

/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
const uncommonFromSentences = (s1, s2) => {
    const freqs = new Map();
    calc_freqs(s1, freqs);
    calc_freqs(s2, freqs);
    const res = [];

    for (const [word, freq] of freqs) {
        if (freq === 1) {
            res.push(word);
        }
    }

    return res
};
