impl Solution {
    pub fn license_key_formatting(s: String, k: i32) -> String {
        let bytes = s.as_bytes();
        let total_valid_chars = bytes.iter().filter(|x| **x != b'-').count() as i32;

        if (total_valid_chars == 0) {
            return "".to_string();
        }

        let total_res_char = total_valid_chars + (total_valid_chars - 1) / k;
        let mut res: Vec<u8> = Vec::with_capacity(total_res_char as usize);
        let mut curr_count = 0_i32;

        for byte in bytes.iter().rev() {
            if *byte == b'-' {
                continue;
            }

            curr_count += 1;

            if curr_count > k {
                curr_count = 1;
                res.push(b'-');
            }

            if *byte >= b'a' && *byte <= b'z' {
                res.push(*byte - 32);
            } else {
                res.push(*byte);
            }
        }

        res.reverse();

        String::from_utf8(res).unwrap()
    }
}
