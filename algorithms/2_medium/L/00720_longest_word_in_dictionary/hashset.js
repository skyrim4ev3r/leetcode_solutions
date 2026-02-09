/**
 * @param {string[]} words
 * @return {string}
 */
const longestWord = (words) => {
    words.sort((a, b) => a.length - b.length);

    const valids = new Set();
    let max_seen_len = 0;

    for (const w of words) {
        const curr_word_len = w.length;

        if (curr_word_len > max_seen_len + 1) {
            break;
        }

        if (curr_word_len > 1 && !valids.has(w.slice(0, curr_word_len - 1))) {
            continue;
        }

        max_seen_len = curr_word_len;
        valids.add(w);
    }

    valid_vec = [];

    for (const v of valids) {
        if (v.length == max_seen_len) {
            valid_vec.push(v);
        }
    }

    valid_vec.sort();

    return valid_vec.length === 0 ? "" : valid_vec[0];
};
