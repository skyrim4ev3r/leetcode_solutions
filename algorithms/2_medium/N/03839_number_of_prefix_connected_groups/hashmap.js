/**
 * @param {string[]} words
 * @param {number} k
 * @return {number}
 */
const prefixConnected = (words, k) => {
    const hashmap = new Map();

    for (const w of words) {
        if (w.length >= k) {
            const prefix = w.substr(0, k);
            hashmap.set(prefix, (hashmap.get(prefix) || 0) + 1);
        }
    }

    return Array.from(hashmap.values()).filter(x => x > 1).length;
};
