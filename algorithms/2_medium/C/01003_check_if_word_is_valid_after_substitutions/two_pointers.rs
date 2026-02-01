impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut left = 0_usize;
        let mut bytes = s.into_bytes();

        for right in 0..bytes.len() {
            if bytes[right] == b'c' {
                if left >= 2 && bytes[left - 1] == b'b' && bytes[left - 2] == b'a' {
                    left -= 2;
                } else {
                    return false;
                }
            } else {
                bytes[left] = bytes[right];
                left += 1;
            }
        }

        left == 0
    }
}
