impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let mut max_i = 0_usize;
        let mut min_i = usize::MAX;
        let mut max_j = 0_usize;
        let mut min_j = usize::MAX;
        let mut found_one = false;  // Flag to check if any '1' is found

        let rows = grid.len();
        let cols = grid[0].len();

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    found_one = true;

                    max_i = i; // Directly assign since var "i" is always growing
                    min_i = min_i.min(i);

                    max_j = max_j.max(j);
                    min_j = min_j.min(j);
                }
            }
        }

        if !found_one {
            return 0;
        }

        ((max_i - min_i + 1) * (max_j - min_j + 1)) as i32
    }
}
