impl Solution {

    #[inline]
    fn is_valid(byte: &u8) -> bool {
        (b'A' <= *byte && *byte <= b'Z') ||
        (b'a' <= *byte && *byte <= b'z') ||
        (b'0' <= *byte && *byte <= b'9')
    }

    #[inline]
    fn to_lower(byte: u8) -> u8 {
        if b'A' <= byte && byte <= b'Z' {
            byte - b'A' + b'a'
        } else {
            byte
        }
    }

    pub fn is_palindrome(s: String) -> bool {
        let mut right = s.len() - 1;
        let mut left = 0;
        let s_bytes = s.into_bytes();

        while left < right {
            if !Self::is_valid(&s_bytes[left]) {
                left += 1;
            } else if !Self::is_valid(&s_bytes[right]) {
                right -= 1;
            } else {
                if Self::to_lower(s_bytes[left]) != Self::to_lower(s_bytes[right]) {
                    return false;
                }
                right -= 1;
                left += 1;
            }
        }

        true
    }
}
