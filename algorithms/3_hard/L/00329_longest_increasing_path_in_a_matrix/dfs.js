const DIRECTIONS = [[1, 0], [0, 1], [-1, 0], [0, -1]];

const dfs = (matrix, dp, i, j, rows, cols) => {
    const cache = dp[i][j];
    if (cache != -1) {
        return cache;
    }

    let longest = 1;
    let curr_cell = matrix[i][j];

    for (const [dx, dy] of DIRECTIONS) {
        const new_i = i + dx;
        const new_j = j + dy;

        if (new_i < 0 || new_j < 0 || new_i >= rows || new_j >= cols || matrix[new_i][new_j] >= curr_cell) {
            continue;
        }

        longest = Math.max(longest, 1 + dfs(matrix, dp, new_i, new_j, rows, cols));
    }

    dp[i][j] = longest;
    return longest;
}

/**
 * @param {number[][]} matrix
 * @return {number}
 */
const longestIncreasingPath = (matrix) => {
    const rows = matrix.length;
    const cols = matrix[0].length;
    const dp = [];
    for (let i = 0; i < rows; ++i) {
        dp[i] = new Array(cols).fill(-1);
    }
    let max = 0;

    for (let i = 0; i < rows; ++i) {
        for (let j = 0; j < cols; ++j) {
            max = Math.max(max, dfs(matrix, dp, i, j, rows, cols));
        }
    }

    return max;
};
