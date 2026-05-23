impl Solution {
    fn check_palindrom(
        bytes: &[u8],
        len: usize,
        mut left: usize,
        mut right: usize,
        max_width: &mut usize,
        max_width_start_idx: &mut usize,
    ) {
        while left > 0 && right < len - 1 && bytes[left - 1] == bytes[right + 1] {
            left -= 1;
            right += 1;
        }

        let width = right - left + 1;

        if width > *max_width {
            *max_width = width;
            *max_width_start_idx = left;
        }
    }

    pub fn longest_palindrome(s: String) -> String {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut max_width = 0_usize;
        let mut max_width_start_idx = 0_usize;

        for i in 0..len {
            if i > 0 && bytes[i - 1] == bytes[i] {
                Self::check_palindrom(bytes, len, i - 1, i, &mut max_width, &mut max_width_start_idx);
            }

            Self::check_palindrom(bytes, len, i, i, &mut max_width, &mut max_width_start_idx);
        }

        String::from_utf8(bytes[max_width_start_idx..(max_width_start_idx + max_width)].to_vec()).unwrap()
    }
}
