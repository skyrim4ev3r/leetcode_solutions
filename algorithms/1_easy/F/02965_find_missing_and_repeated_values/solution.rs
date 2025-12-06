impl Solution {
    pub fn find_missing_and_repeated_values(mut grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = grid.len();
        let mut repeated = 0_i32;
        let mut missed = 0_i32;

        for i in 0..n {
            for j in 0..n {
                let val = grid[i][j].abs() as usize;
                let other_i = ((val + n - 1) / n) - 1;
                let mut other_j = val % n;

                if (other_j == 0) {
                    other_j = n - 1;
                } else {
                    other_j -= 1;
                }

                if grid[other_i][other_j] < 0 {
                    repeated = grid[i][j].abs();
                } else {
                    grid[other_i][other_j] *= -1;
                }
            }
        }

       for i in 0..n {
            for j in 0..n {
                if grid[i][j] > 0 {
                    missed = (i * n + (j + 1)) as i32;
                    return vec![repeated, missed];
                }
            }
        }

        vec![-1, -1]
    }
}
