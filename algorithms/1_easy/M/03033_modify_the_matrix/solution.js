/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
const modifiedMatrix = (matrix) => {
    const rows = matrix.length;
    const cols = matrix[0].length;
    const result = [];

    for (let i = 0; i < rows; ++i) {
        result[i] = new Array(cols).fill(0);
    }

    for (let j = 0; j < cols; ++j) {
        let max = Number.MIN_SAFE_INTEGER;

        for (let i = 0; i < rows; ++i) {
            max = Math.max(max, matrix[i][j]);
        }

        for (let i = 0; i < rows; ++i) {
            if (matrix[i][j] === -1) {
                result[i][j] = max;
            } else {
                result[i][j] = matrix[i][j];
            }
        }
    }

    return result;
};
