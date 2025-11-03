impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        let mut sum = 0_i32;
        let mut max_g = 0_i32;

        for g in gain.into_iter() {
            sum += g;
            max_g = max_g.max(sum);
        }

        max_g
    }
}
