impl Solution {
    pub fn max_score(s: String) -> i32 {
        let bytes = s.as_bytes();
        let total_ones: usize = bytes.iter().filter(|x| **x == b'1').count();
        let len = bytes.len();
        let mut curr_ones = 0_usize;
        let mut curr_zeros = 0_usize;
        let mut max_score = 0_usize;

        for i in 0..(len - 1) {
            if bytes[i] == b'0' {
                curr_zeros += 1;
            } else {
                curr_ones += 1;
            }

            max_score = max_score.max(curr_zeros + total_ones - curr_ones);
        }

        max_score as i32
    }
}
