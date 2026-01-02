impl Solution {
    pub fn count_k_constraint_substrings(s: String, k: i32) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut left = 0_usize;
        let mut count = 0_usize;
        let mut zeros = 0_i32;
        let mut ones = 0_i32;

        for right in 0..len {
            if bytes[right] == b'0' {
                zeros += 1;
            } else {
                ones += 1;
            }

            while ones > k && zeros > k {
                if bytes[left] == b'0' {
                    zeros -= 1;
                } else {
                    ones -= 1;
                }

                left += 1;
            }

            count += right - left + 1;
        }

        count as i32
    }
}
