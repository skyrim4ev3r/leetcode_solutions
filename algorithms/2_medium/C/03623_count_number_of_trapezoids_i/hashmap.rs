use std::collections::HashMap;

impl Solution {
    pub fn count_trapezoids(points: Vec<Vec<i32>>) -> i32 {
        let mut hashmap: HashMap<i32, i32> = HashMap::new();
        const MOD_TO: i64 = 1_000_000_007;
        let mut total_trapezoid_count = 0_i64;
        let mut total_selection = 0_i64;

        for point in points.iter() {
            *hashmap.entry(point[1]).or_insert(0) += 1;
        }

        for (_, count_i32) in hashmap.into_iter() {
            if count_i32 > 1 {
                let count = count_i32 as i64;
                let curr_selection = ((count * (count - 1)) / 2) % MOD_TO;
                total_trapezoid_count = (total_trapezoid_count + total_selection * curr_selection) % MOD_TO;
                total_selection = (total_selection + curr_selection) % MOD_TO;
            }
        }

        total_trapezoid_count as i32
    }
}
