impl Solution {
    pub fn is_valid(s: String) -> bool {

        let mut stack: Vec<u8> = Vec::new();

        for byte in s.into_bytes().into_iter() {
            match byte {
                b'}' | b']' | b')' => {
                    if let Some(top_byte) = stack.pop() {
                        if (byte == b'}' && top_byte != b'{') ||
                           (byte == b']' && top_byte != b'[') ||
                           (byte == b')' && top_byte != b'(')
                        {
                            return false;
                        }
                    } else {
                        return false;
                    }
                },
                _ => {
                    stack.push(byte);
                },
            } 
        }

        stack.is_empty()
    }
}
