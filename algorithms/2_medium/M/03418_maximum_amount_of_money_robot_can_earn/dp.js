/**
 * @param {number[][]} coins
 * @return {number}
 */
const maximumAmount = (coins) => {
    const rows = coins.length;
    const cols = coins[0].length;
    const skips = 3;
    const costs = [];

    for (let i = 0; i <= rows; ++i) {
        costs[i] = [];
        for (let j = 0; j <= cols; ++j) {
           costs[i][j] = new Array(skips).fill(Number.MIN_SAFE_INTEGER);
        }
    }
    costs[0][1] = new Array(skips).fill(0);

    for (let i = 0; i < rows; ++i) {
        for (let j = 0; j < cols; ++j) {
            for(let k = 0; k < skips; ++k) {
                let curr_cost = coins[i][j] + Math.max(costs[i][j + 1][k], costs[i + 1][j][k]);

                if (k > 0) {
                    curr_cost = Math.max(curr_cost, costs[i][j + 1][k - 1], costs[i + 1][j][k - 1]);
                }

                costs[i + 1][j + 1][k] = curr_cost;
            }
        }
    }

    return Math.max(...costs[rows][cols]);
};
