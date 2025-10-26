impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];
    
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let total_nums = rows * cols;

        let mut res: Vec<i32> = Vec::with_capacity(total_nums);
        let mut is_seen = vec![vec![false; cols]; rows];
        let mut i = 0_usize;
        let mut j = 0_usize;
        let mut curr_dir_index = 0;

        for _ in 0..total_nums {
            res.push(matrix[i][j]);
            is_seen[i][j] = true;

            let (dx, dy) = Self::DIRECTIONS[curr_dir_index];
            let next_i = (i as isize + dx) as usize;
            let next_j = (j as isize + dy) as usize;

            if next_i >= rows || next_j >= cols || is_seen[next_i][next_j] {
                curr_dir_index = (curr_dir_index + 1) % 4;
                let (dx, dy) = Self::DIRECTIONS[curr_dir_index];
                i = (i as isize + dx) as usize;
                j = (j as isize + dy) as usize;
            } else {
                i = next_i;
                j = next_j;
            }
        }

        res
    }
}
