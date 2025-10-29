impl Solution {
    fn is_palindrome(s_bytes: &[u8], mut left: usize, mut right: usize, penalty: i32) -> bool {
        while left < right {
            if s_bytes[left] != s_bytes[right] {
                if penalty > 0 {
                    return Self::is_palindrome(s_bytes, left + 1, right, penalty - 1) ||
                           Self::is_palindrome(s_bytes, left, right - 1, penalty - 1);
                } else {
                    return false;
                }
            }

            left += 1;
            right -= 1;
        }

        true
    }

    pub fn valid_palindrome(s: String) -> bool {
        let right = s.len() - 1;
        let left = 0_usize;
        let penalty = 1_i32;

        Self::is_palindrome(&s.into_bytes(), left, right, penalty)
    }
}
