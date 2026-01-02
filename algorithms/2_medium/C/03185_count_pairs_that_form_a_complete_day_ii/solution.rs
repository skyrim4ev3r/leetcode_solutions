impl Solution {
    pub fn count_complete_day_pairs(hours: Vec<i32>) -> i64 {
        let mut freqs = [0_i64; 24];
        let mut count = 0_i64;

        for h in hours.into_iter() {
            freqs[(h % 24) as usize] += 1;
        }

        count += freqs[0] * (freqs[0] - 1) / 2;
        count += freqs[12] * (freqs[12] - 1) / 2;

        for i in 1..=11 {
            count += freqs[i] * freqs[24 - i];
        }

        count
    }
}
