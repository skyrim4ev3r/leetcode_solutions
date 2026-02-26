impl Solution {
    pub fn zigzag_traversal(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let rows = grid.len();
        let cols = grid[0].len();
        let total = rows * cols;
        let mut res: Vec<i32> = Vec::with_capacity((total >> 1) + (total & 1));

        for step in (0..total).step_by(2) {
            let i = step / cols;
            let j = if (i & 1) == 0 { step % cols } else { cols - 1 -  (step % cols) };
            res.push(grid[i][j]);
        }

        res
    }
}
