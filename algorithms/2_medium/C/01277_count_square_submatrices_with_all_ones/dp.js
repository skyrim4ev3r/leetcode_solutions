/**
 * @param {number[][]} matrix
 * @return {number}
 */
const countSquares = (matrix) => {
    const rows = matrix.length;
    const cols = matrix[0].length;
    const dp = [];
    for (let i = 0; i < rows + 1; ++i) {
        dp[i] = new Array(cols + 1).fill(0);
    }

    let count = 0;

    for (let i = 0; i < rows; ++i) {
        for (let j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                dp[i + 1][j + 1] = 1 + Math.min(dp[i + 1][j], dp[i][j + 1], dp[i][j]);
                count += dp[i + 1][j + 1];
            }
        }
    }

    return count;
};
