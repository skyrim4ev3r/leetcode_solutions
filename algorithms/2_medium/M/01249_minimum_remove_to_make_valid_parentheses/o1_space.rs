impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        let mut bytes = s.into_bytes();

        let mut balance = 0_i32;
        for byte in bytes.iter_mut() {
            if *byte == b'(' {
                balance += 1
            } else if *byte == b')' {
                if balance > 0 {
                    balance -= 1;
                } else {
                    *byte = b'*';
                }
            }
        }

        let mut balance = 0_i32;
        for byte in bytes.iter_mut().rev() {
            if *byte == b')' {
                balance += 1
            } else if *byte == b'(' {
                if balance > 0 {
                    balance -= 1;
                } else {
                    *byte = b'*';
                }
            }
        }

        bytes.retain(|byte| *byte != b'*');

        String::from_utf8(bytes).unwrap()
    }
}
