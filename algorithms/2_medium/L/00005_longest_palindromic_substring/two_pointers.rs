impl Solution {

    #[inline]
    fn helper(s_bytes: &Vec<u8>, len: &usize, left: &mut usize, right: &mut usize, max_start_idx: &mut usize, max_width: &mut usize) {
        while *left > 0 && *right < *len - 1 && s_bytes[*left - 1] == s_bytes[*right + 1] {
            *left -= 1;
            *right += 1;
        }

        let width = *right - *left + 1;

        if width > *max_width {
            *max_width = width;
            *max_start_idx = *left;
        }
    }


    pub fn longest_palindrome(s: String) -> String {

        let s_bytes = s.into_bytes();
        let len = s_bytes.len();
        let mut max_width = 0_usize;
        let mut max_start_idx = 0_usize;
        let mut left = 0_usize;
        let mut right = 0_usize;

        for i in 0..len {
            if i > 0 && s_bytes[i - 1] == s_bytes[i] {
                left = i - 1;
                right = i;
                Self::helper(&s_bytes, &len, &mut left, &mut right, &mut max_start_idx, &mut max_width);
            }

            left = i;
            right = i;
            Self::helper(&s_bytes, &len, &mut left, &mut right, &mut max_start_idx, &mut max_width);
        }

        String::from_utf8_lossy(&s_bytes[max_start_idx..(max_start_idx + max_width)]).into_owned()
    }
}
