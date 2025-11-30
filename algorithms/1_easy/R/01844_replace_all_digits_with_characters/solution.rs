impl Solution {
    pub fn replace_digits(s: String) -> String {
        let mut s_bytes = s.into_bytes();
        let len = s_bytes.len();

        for i in (1..len).step_by(2) {
            s_bytes[i] = s_bytes[i] - b'0' + s_bytes[i - 1];
        }

        String::from_utf8(s_bytes).unwrap()
    }
}
