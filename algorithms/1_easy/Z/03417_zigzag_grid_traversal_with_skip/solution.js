/**
 * @param {number[][]} grid
 * @return {number[]}
 */
const zigzagTraversal = (grid) => {
    const rows = grid.length;
    const cols = grid[0].length;
    const total = rows * cols;
    const res = [];

    for (let step = 0; step < total; step += 2) {
        const i = Math.floor(step / cols);
        const j = (i & 1) == 0 ? step % cols : cols - 1 -  (step % cols);
        res.push(grid[i][j]);
    }

    return res;
};
