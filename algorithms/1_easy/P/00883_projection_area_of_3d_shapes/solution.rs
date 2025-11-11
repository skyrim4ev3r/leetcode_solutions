impl Solution {
    pub fn projection_area(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut count_up_down = 0_i32;
        let mut count_left_right = 0_i32;
        let mut count_front_back = 0_i32;

        for i in 0..n {
            let mut max_left_right = 0;

            for j in 0..n {
                if grid[i][j] > 0 {
                    count_up_down += 1;
                }

                max_left_right = max_left_right.max(grid[i][j]);
            }

            count_left_right += max_left_right;
        }

        for j in 0..n {
            let mut max_front_back = 0_i32;

            for i in 0..n {
                max_front_back = max_front_back.max(grid[i][j]);
            }

            count_front_back += max_front_back;
        }

        count_front_back + count_left_right + count_up_down
    }
}
