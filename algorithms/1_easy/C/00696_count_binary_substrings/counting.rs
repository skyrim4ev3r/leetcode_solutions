impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut curr_count = 1_i32;
        let mut prev_count = 0_i32;
        let mut res = 0_i32;

        for i in 1..len {
            if bytes[i] != bytes[i - 1] {
                res += curr_count.min(prev_count);
                prev_count = curr_count;
                curr_count = 1;
            } else {
                curr_count += 1;
            }
        }

        res += curr_count.min(prev_count);

        return res;
    }
}
