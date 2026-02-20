/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
const maxPathScore = (grid, k) => {
    const rows = grid.length;
    const cols = grid[0].length;

    const dp = []
    for (let i = 0; i < rows; ++i) {
        dp[i] = [];

        for (let j = 0; j < cols; ++j) {
            dp[i][j] = new Array(k + 1).fill(-1);
        }
    }

    dp[0][0][0] = 0;

    for (let i = 0; i < rows; ++i) {
        for (let j = 0; j < cols; ++j) {
            const score_cell = grid[i][j];
            const cost_cell = score_cell != 0 ? 1 : 0;

            if (i > 0) {
                for (let c = 0 ; c <= k; ++c) {
                    if (dp[i - 1][j][c] != -1) {
                        if (c + cost_cell <= k) {
                            dp[i][j][c + cost_cell] = Math.max(dp[i][j][c + cost_cell], dp[i - 1][j][c] + score_cell);
                        }
                    }
                }
            }

            if (j > 0) {
                for (let c = 0; c <= k; ++c) {
                    if (dp[i][j - 1][c] != -1) {
                        if (c + cost_cell <= k) {
                            dp[i][j][c + cost_cell] = Math.max(dp[i][j][c + cost_cell], dp[i][j - 1][c] + score_cell);
                        }
                    }
                }
            }
        }
    }

    return Math.max(...dp[rows - 1][cols - 1]);
};
