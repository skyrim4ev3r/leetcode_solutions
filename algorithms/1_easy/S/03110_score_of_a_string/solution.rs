impl Solution {
    pub fn score_of_string(s: String) -> i32 {
        s.into_bytes().windows(2).fold(0_i32, |mut acc, w| acc + (w[1] as i32 - w[0] as i32).abs())
    }
}
