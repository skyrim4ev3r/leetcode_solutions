impl Solution {
    pub fn minimum_total(mut triangle: Vec<Vec<i32>>) -> i32 {
        let rows = triangle.len();

        for curr_row in (0..rows - 1).rev() {
            let next_row = curr_row + 1;

            for curr_col in 0..triangle[curr_row].len() {
                triangle[curr_row][curr_col] += triangle[next_row][curr_col].min(triangle[next_row][curr_col + 1]);
            }
        }

        triangle[0][0]
    }
}
