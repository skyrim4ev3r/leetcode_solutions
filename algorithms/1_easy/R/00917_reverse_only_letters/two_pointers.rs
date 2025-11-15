impl Solution {
    #[inline]
    fn is_valid_char(byte: &u8) -> bool {
        (*byte >= b'a' && *byte <= b'z') || (*byte >= b'A' && *byte <= b'Z')
    }

    pub fn reverse_only_letters(s: String) -> String {
        let mut bytes = s.into_bytes();
        let mut left = 0_usize;
        let mut right = bytes.len() - 1;

        while left < right {
            while left < right && !Self::is_valid_char(&bytes[right])  {
                right -= 1;
            }

            while left < right && !Self::is_valid_char(&bytes[left]) {
                left += 1;
            }

            if left >= right {
                break;
            }

            let temp = bytes[right];
            bytes[right] = bytes[left];
            bytes[left] = temp;

            right -= 1;
            left += 1;
        }

        String::from_utf8(bytes).unwrap()
    }
}
