impl Solution {
    pub fn shift_grid(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let m = grid.len();
        let n = grid[0].len();
        let shift_counts = (k as usize) % (m * n);

        if shift_counts == 0 {
            return grid;
        }

        let mut res = vec![vec![0_i32; n]; m];
        let mut res_i = shift_counts / n;
        let mut res_j = shift_counts % n;

        for i in 0..m {
            for j in 0..n {
                res[res_i][res_j] = grid[i][j];
                res_j += 1;

                if res_j == n {
                    res_j = 0;
                    res_i += 1;

                    if res_i == m {
                        res_i = 0;
                    }
                }
            }
        }

        res
    }
}
