impl Solution {
    pub fn maximum_happiness_sum(mut happiness: Vec<i32>, k: i32) -> i64 {
        happiness.sort_unstable_by(|a, b| b.cmp(&a));
        let mut max = 0_i64;

        for (i, h) in happiness.into_iter().enumerate() {
            let i_i32 = i as i32;

            if h <= i_i32 || i_i32 == k {
                break;
            }

            max += (h as i64) - i as i64;
        }

        max
    }
}
