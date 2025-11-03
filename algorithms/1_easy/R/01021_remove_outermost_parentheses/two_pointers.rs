impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {

        let s_bytes = s.into_bytes();
        let s_bytes_len = s_bytes.len();
        let mut res: Vec<u8> = Vec::new();
        let mut left_index = 0_usize;
        let mut open_count = 0_i32;
        let mut close_count = 0_i32;

        for i in 0..s_bytes_len {
            if s_bytes[i] == b'(' {
                open_count += 1;
            } else {
                close_count += 1;
            }

            if open_count == close_count {
                res.extend(s_bytes[(left_index + 1)..i].to_vec());
                left_index = i + 1;
                open_count = 0;
                close_count = 0;
            }
        }

        String::from_utf8(res).unwrap()
    }
}
