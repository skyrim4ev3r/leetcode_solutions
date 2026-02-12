/**
 * @param {number} upper
 * @param {number} lower
 * @param {number[]} colsum
 * @return {number[][]}
 */
const reconstructMatrix = (upper, lower, colsum) => {
    const sum = colsum.reduce((acc, x) => acc + x, 0);

    if (sum != upper + lower) {
        return [];
    }

    const count_twos = colsum.filter(num => num === 2).length;

    if (count_twos > upper || count_twos > lower) {
        return [];
    }

    const cols = colsum.length;
    const res = [new Array(cols).fill(0), new Array(cols).fill(0)];

    let remain_upper = upper - count_twos;
    let remian_lower = lower - count_twos;

    for (let j = 0; j < cols; j += 1) {
        if (colsum[j] === 1) {
            if (remain_upper > 0) {
                res[0][j] = 1;
                remain_upper -= 1;
            } else {
                res[1][j] = 1;
                remian_lower -= 1;
            }
        } else if (colsum[j] === 2) {
            res[0][j] = 1;
            res[1][j] = 1;
        }
    }

    return res;
};
