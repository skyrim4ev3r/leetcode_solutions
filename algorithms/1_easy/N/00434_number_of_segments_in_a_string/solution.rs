impl Solution {
    pub fn count_segments(s: String) -> i32 {
        let mut segments = 0_i32;
        let bytes = s.as_bytes();
        let len = s.len();

        for i in 0..len {
            if bytes[i] != b' ' && (i == 0 || bytes[i - 1] == b' ') {
                segments += 1;
            }
        }

        segments
    }
}
