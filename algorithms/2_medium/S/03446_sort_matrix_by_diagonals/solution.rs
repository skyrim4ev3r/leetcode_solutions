impl Solution {
    pub fn sort_matrix(mut grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {

        let n = grid.len();

        // Sort upper diagonals
        for pos in 1..n {
            let mut i = 0;
            let mut j = pos;
            let mut values: Vec<i32> = vec![];

            while j < n {
                values.push(grid[i][j]);
                j += 1;
                i += 1;
            }

            values.sort_unstable(); 

            i = 0;
            j = pos;
            while j < n {
                grid[i][j] = values[i];
                i += 1;
                j += 1;
            }
        }

        // Sort lower diagonals
        for pos in 0..n {
            let mut i = pos;
            let mut j = 0;
            let mut values: Vec<i32> = vec![];

            while i < n {
                values.push(grid[i][j]);
                j += 1;
                i += 1;
            }

            values.sort_unstable_by(|a, b| b.cmp(a)); 

            i = pos;
            j = 0;
            while i < n {
                grid[i][j] = values[j];
                i += 1;
                j += 1;
            }
        }

        grid
    }
}
