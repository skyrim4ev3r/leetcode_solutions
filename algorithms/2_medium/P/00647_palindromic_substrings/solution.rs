impl Solution {
    fn calc_len_palindrome(bytes: &[u8], len: isize, mut lo: isize, mut hi: isize) -> i32 {
        if lo < 0 || hi >= len || bytes[lo as usize] != bytes[hi as usize] {
            return 0;
        }

        while lo >= 0 && hi < len && bytes[lo as usize] == bytes[hi as usize] {
            lo -= 1;
            hi += 1;
        }

        (hi - lo - 1) as i32
    }

    pub fn count_substrings(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = s.len() as isize;
        let mut cnt = 0_i32;

        for i in 0..len {
            let len_odd = Self::calc_len_palindrome(bytes, len, i, i);
            let len_even = Self::calc_len_palindrome(bytes, len, i - 1, i);

            cnt += ((len_odd + 1) / 2) + (len_even / 2);
        }

        cnt
    }
}
