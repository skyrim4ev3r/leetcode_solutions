impl Solution {
    pub fn to_lower_case(s: String) -> String {
        let mut bytes = s.into_bytes();

        for byte in bytes.iter_mut() {
            if *byte >= b'A' && *byte <= b'Z' {
                *byte +=32;
            }
        }

        String::from_utf8(bytes).unwrap()
    }
}
