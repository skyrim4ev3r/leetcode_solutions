impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut stack: Vec<u8> = Vec::with_capacity(s.len());

        for byte in s.as_bytes().iter() {
            match *byte {
                b')' => {
                    if let Some(other_byte) = stack.last() && *other_byte == b'(' {
                        stack.pop();
                    } else {
                        stack.push(*byte);
                    }
                },
                _ => stack.push(*byte),
            }
        }

        stack.len() as i32
    }
}
