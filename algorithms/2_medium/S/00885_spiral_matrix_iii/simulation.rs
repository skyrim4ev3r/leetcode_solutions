impl Solution {
    pub fn spiral_matrix_iii(rows: i32, cols: i32, mut i: i32, mut j: i32) -> Vec<Vec<i32>> {
        let target_len = (rows * cols) as usize;
        let mut res: Vec<Vec<i32>> = Vec::with_capacity(target_len);
        const DIRECTIONS: [(i32, i32); 4] = [(0, 1), (1, 0), (0, -1), (-1, 0)];
        let mut dir_index = 0_usize;
        let mut curr_path_len = 0_i32;
        let mut flip_flop_should_increase_path = true;

        loop {
            if flip_flop_should_increase_path {
                curr_path_len += 1;
            }
            flip_flop_should_increase_path = !flip_flop_should_increase_path;

            for _ in 0..curr_path_len {
                if i >= 0 && i < rows && j >=0 && j < cols {
                    res.push(vec![i, j]);

                    if res.len() == target_len {
                        return res;
                    }
                }

                i += DIRECTIONS[dir_index].0;
                j += DIRECTIONS[dir_index].1;
            }

            dir_index = (dir_index + 1) % 4; 
        }

        res
    }
}
