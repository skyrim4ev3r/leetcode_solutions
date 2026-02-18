/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
const findContentChildren = (g, s) => {
    s.sort((a, b) => a - b);
    g.sort((a, b) => a - b);

    const len_s = s.length;
    const len_g = g.length;
    let count = 0;
    let index_g = 0;
    let index_s = 0;

    while (index_s < len_s && index_g < len_g) {
        if (g[index_g] <= s[index_s]) {
            count += 1;
            index_g += 1;
        }

        index_s += 1;
    }

    return count;
};
