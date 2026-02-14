/*
    Each glass with index j has 2 parent glasses: j and j - 1.

    Each glass receives half of the amount that its parents throw.

    using 2 arrays:
        -One array tracks the fill percentage of the glasses.
        -Another array tracks how much they throw.

    Fill the first glass parent with 2 * poured, so the first glass gets half of it.
        throw_info[0] = 2.0 * poured
*/

/**
 * @param {number} poured
 * @param {number} query_row
 * @param {number} query_glass
 * @return {number}
 */
const champagneTower = (poured, query_row, query_glass) => {
    const fill_info = new Array(query_row + 1).fill(0.0);
    const throw_info = new Array(query_row + 1).fill(0.0);
    throw_info[0] = 2.0 * poured;

    for (let i = 0; i < query_row + 1; ++i) {
        for (let j = i; j >= 0; --j) {
            const amount = (throw_info[j] / 2.0) + (j > 0 ? throw_info[j - 1] / 2.0 : 0.0);
            fill_info[j] =  Math.min(amount, 1.0);
            throw_info[j] = Math.max(amount - 1.0, 0.0);
        }
    }

    return fill_info[query_glass];
};
