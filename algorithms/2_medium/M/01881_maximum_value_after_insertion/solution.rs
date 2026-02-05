impl Solution {
    pub fn max_value(n: String, x: i32) -> String {
        let mut bytes = n.into_bytes();
        let len = bytes.len();
        let byte = x as u8 + b'0';

        if bytes[0] == b'-' {
            let mut i = 1_usize;

            while i < len && bytes[i] <= byte {
                i += 1;
            }

            bytes.insert(i, byte);
        } else {
            let mut i = 0_usize;

            while i < len && bytes[i] >= byte {
                i += 1;
            }

            bytes.insert(i, byte);
        }

        String::from_utf8(bytes).unwrap()
    }
}
