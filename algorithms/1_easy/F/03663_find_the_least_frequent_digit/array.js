/**
 * @param {number} n
 * @return {number}
 */
const getLeastFrequentDigit = (n) => {
    const freqs = new Array(10).fill(0);

    while (n > 0) {
        freqs[n % 10] += 1;
        n = Math.floor(n /10);
    }

    let min_freq = Number.MAX_SAFE_INTEGER;
    let min_freq_index = 0;

    for (let i = 0 ; i < 10; ++i) {
        if (freqs[i] != 0 && freqs[i] < min_freq) {
            min_freq = freqs[i];
            min_freq_index = i;
        }
    }

    return min_freq_index;
};
