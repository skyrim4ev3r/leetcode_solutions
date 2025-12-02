use std::collections::HashMap;

impl Solution {
    pub fn count_trapezoids(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_unstable_by(|a, b| a[1].cmp(&b[1]));

        const MOD_TO: i64 = 1_000_000_007;
        let mut total_trapezoid_count = 0_i64;
        let mut total_selection = 0_i64;
        let mut count = 0_i64;
        let mut prev_y = i32::MIN;

        for point in points.iter() {
            if point[1] == prev_y {
                count += 1;
            } else {
                if count > 1 {
                    let curr_selection = ((count * (count - 1)) / 2) % MOD_TO;
                    total_trapezoid_count = (total_trapezoid_count + total_selection * curr_selection) % MOD_TO;
                    total_selection = (total_selection + curr_selection) % MOD_TO;
                }                

                prev_y = point[1];
                count = 1;
            }
        }

        if count > 1 {
            let curr_selection = ((count * (count - 1)) / 2) % MOD_TO;
            total_trapezoid_count = (total_trapezoid_count + total_selection * curr_selection) % MOD_TO;
        }

        total_trapezoid_count as i32
    }
}
