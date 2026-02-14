impl Solution {
    pub fn check_ones_segment(s: String) -> bool {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut count = 0_i32;

        for i in 0..len {
            if bytes[i] == b'1' && (i == 0 || bytes[i - 1] == b'0') {
                count += 1;

                if count > 1 {
                    return false;
                }
            }
        }

        true
    }
}
