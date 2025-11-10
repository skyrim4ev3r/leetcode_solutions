impl Solution {
    pub fn reverse_submatrix(mut grid: Vec<Vec<i32>>, x: i32, y: i32, k: i32) -> Vec<Vec<i32>> {
        let (k_usize, x_usize, y_usize) = (k as usize, x as usize, y as usize);

        for y_ofs in 0..k_usize {
            let mut lower = x_usize;
            let mut upper = x_usize + k_usize - 1;
            let curr_y = y_usize + y_ofs;

            while lower < upper{
                let temp = grid[lower][curr_y];
                grid[lower][curr_y] = grid[upper][curr_y];
                grid[upper][curr_y] = temp;

                lower += 1;
                upper -= 1;
            }
        }

        grid
    }
}
