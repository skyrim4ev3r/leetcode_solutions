impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack: Vec<u8> = Vec::new();

        for byte in s.as_bytes().iter() {
            if *byte == b'c' {
                let len = stack.len();

                if len >= 2 && stack[len - 1] == b'b' && stack[len - 2] == b'a' {
                    stack.pop();
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(*byte);
            }
        }

        stack.is_empty()
    }
}
