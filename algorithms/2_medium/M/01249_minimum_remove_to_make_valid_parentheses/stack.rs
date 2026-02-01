impl Solution {
    pub fn min_remove_to_make_valid(s: String) -> String {
        let mut stack: Vec<(u8, usize)> = Vec::new();
        let mut bytes = s.into_bytes();

        for (i, byte) in bytes.iter().enumerate() {
            if *byte == b'(' {
                stack.push((*byte, i));
            } else if *byte == b')' {
                if let Some((top_byte, _)) = stack.last() && *top_byte == b'(' {
                    stack.pop();
                } else {
                    stack.push((*byte, i));
                }
            }
        }

        for (_, index) in stack.into_iter() {
            bytes[index] = b'*';
        }

        bytes.retain(|byte| *byte != b'*');

        String::from_utf8(bytes).unwrap()
    }
}
