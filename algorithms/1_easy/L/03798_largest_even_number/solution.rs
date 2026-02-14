impl Solution {
    pub fn largest_even(s: String) -> String {
        let mut bytes = s.into_bytes();

        while let Some(byte) = bytes.last() && *byte == b'1' {
            bytes.pop();
        }

        String::from_utf8(bytes).unwrap()
    }
}
