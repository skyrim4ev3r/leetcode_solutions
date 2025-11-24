impl Solution {
    #[inline]
    fn custom_parse(bytes: &[u8]) -> Vec<u8> {
        let mut final_bytes: Vec<u8> = Vec::new();

        for byte in bytes {
            if *byte == b'#' {
                if !final_bytes.is_empty() {
                    final_bytes.pop();
                }
            } else {
                final_bytes.push(*byte);
            }
        }

        final_bytes
    }

    pub fn backspace_compare(s: String, t: String) -> bool {
        Self::custom_parse(s.as_bytes()) == Self::custom_parse(t.as_bytes())
    }
}
