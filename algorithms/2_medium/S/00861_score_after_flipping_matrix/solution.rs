impl Solution {
    pub fn matrix_score(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut res = 0_usize;

        for i in 0..m {
            if grid[i][0] == 0 {
                for j in 0..n {
                    grid[i][j] = if grid[i][j] == 0 {1} else {0};
                }
            }
        }

        for j in 0..n {
            let mut count_ones = 0_usize;

            for i in 0..m {
                if grid[i][j] == 1 {
                    count_ones +=1;
                }
            }

            let max = count_ones.max(m - count_ones);
            let pow = n - 1 - j;

            res += max * (2_usize.pow(pow as u32));
        }

        res as i32
    }
}
