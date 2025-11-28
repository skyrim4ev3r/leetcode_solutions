impl Solution {
    #[inline]
    fn are_consecutive(a: &u8, b: &u8) -> bool {
        *a == *b - 1 ||
        *a == *b + 1 ||
        (*a == b'z' && *b == b'a') ||
        (*a == b'a' && *b == b'z')
    }

    pub fn resulting_string(s: String) -> String {
        let mut stack: Vec<u8> = Vec::new();

        for byte in s.as_bytes() {
            if let Some(top) = stack.last() && Self::are_consecutive(top, byte) {
                stack.pop();
            } else {
                stack.push(*byte);
            }
        }

        String::from_(stack).unwrap()
    }
}
