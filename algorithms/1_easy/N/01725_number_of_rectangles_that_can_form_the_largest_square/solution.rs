use std::collections::HashMap;

impl Solution {
    pub fn count_good_rectangles(rectangles: Vec<Vec<i32>>) -> i32 {
        let mut count = 0_i32;
        let mut max_len = -1_i32;

        for rec in rectangles.into_iter() {
            let curr_len = rec[0].min(rec[1]);

            if max_len < curr_len {
                max_len = curr_len;
                count = 1;
            } else if max_len == curr_len {
                count += 1;
            }
        }

        count
    }
}
