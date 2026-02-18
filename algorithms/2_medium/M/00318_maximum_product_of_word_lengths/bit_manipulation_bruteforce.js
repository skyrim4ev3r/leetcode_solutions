/**
 * @param {string[]} words
 * @return {number}
 */
const maxProduct = (words) => {
    const len = words.length;
    const masks = new Array(len).fill(0);

    for (let i = 0; i < len; ++i) {
        let mask = 0;

        for (const ch of words[i]) {
            mask = mask | (1 << (ch.charCodeAt(0) - 'a'.charCodeAt(0)));
        }

        masks[i] = mask;
    }

    let max_product_len = 0;

    for (let i = 0; i < len; ++i) {
        for (let j = i + 1; j < len; ++j) {
            if ((masks[i] & masks[j]) === 0) {
                max_product_len = Math.max(max_product_len, words[i].length * words[j].length);
            }
        }
    }

    return max_product_len;
};
