impl Solution {
    fn remove_occurrences_helper(s_bytes: &mut Vec<u8>, part_bytes: &Vec<u8>) -> bool {
        let part_len = part_bytes.len();
        for (index, window) in s_bytes.windows(part_len).enumerate() {
            if window == part_bytes {
                *s_bytes = [&s_bytes[0..index], &s_bytes[index + part_len..]].concat();
                return true;
            }
        }

        false
    }

    pub fn remove_occurrences(s: String, part: String) -> String {
        let mut s_bytes = s.into_bytes();
        let part_bytes = part.into_bytes();

        while Self::remove_occurrences_helper(&mut s_bytes, &part_bytes) {}

        String::from_utf8(s_bytes).unwrap()
    }
}
