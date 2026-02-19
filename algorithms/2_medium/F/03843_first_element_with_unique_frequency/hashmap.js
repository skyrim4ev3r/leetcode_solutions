/**
 * @param {number[]} nums
 * @return {number}
 */
const firstUniqueFreq = (nums) => {
    const freqs = new Map();

    for (const num of nums) {
        freqs.set(num, (freqs.get(num) || 0) + 1);
    }

    const freqs_of_freqs = new Map();

    for (const freq of freqs.values()) {
        freqs_of_freqs.set(freq, (freqs_of_freqs.get(freq) || 0) + 1);
    }

    for (const num of nums) {
        const freq = freqs.get(num);

        if (freqs_of_freqs.get(freq) === 1) {
            return num;
        }
    }

    return -1;
};
