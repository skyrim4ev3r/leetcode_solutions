impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {

        let mut count = 0;
        let cols = grid[0].len();

        for row in grid.into_iter() {
            count += row.iter()
                        .rev()
                        .position(|&x| x > -1)
                        .unwrap_or(cols);
        }

        count as i32
    }
}
