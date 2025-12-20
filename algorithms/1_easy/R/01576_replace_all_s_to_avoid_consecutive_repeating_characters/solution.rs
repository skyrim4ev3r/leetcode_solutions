impl Solution {
    pub fn modify_string(s: String) -> String {
        let mut bytes = s.into_bytes();
        let len = bytes.len();

        for i in 0..len {
            if bytes[i] == b'?' {
                let mut a_allowed = true;
                let mut b_allowed = true;

                if (i > 0 && bytes[i - 1] == b'a') || (i + 1 < len && bytes[i + 1] == b'a') {
                    a_allowed = false;
                }

                if (i > 0 && bytes[i - 1] == b'b') || (i + 1 < len && bytes[i + 1] == b'b') {
                    b_allowed = false;
                }

                if a_allowed {
                    bytes[i] = b'a';
                } else if b_allowed {
                    bytes[i] = b'b';
                } else {
                    bytes[i] = b'c';
                }
            }
        }

        String::from_utf8(bytes).unwrap()
    }
}
