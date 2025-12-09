impl Solution {
    const MAX_WIDTH: i32 = 100;

    pub fn number_of_lines(widths: Vec<i32>, s: String) -> Vec<i32> {
        let mut lines_count = 1_i32;
        let mut curr_width = 0_i32;

        for byte in s.as_bytes().iter() {
            let byte_width = widths[(*byte - b'a') as usize];

            if curr_width + byte_width <= Self::MAX_WIDTH {
                curr_width += byte_width;
            } else {
                lines_count += 1;
                curr_width = byte_width;
            }
        }

        vec![lines_count, curr_width]
    }
}
