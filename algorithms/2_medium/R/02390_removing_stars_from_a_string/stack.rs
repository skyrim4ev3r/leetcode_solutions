impl Solution {
    pub fn remove_stars(s: String) -> String {
        let mut stack: Vec<u8> = Vec::new();

        for byte in s.into_bytes().into_iter() {
            if byte == b'*' && !stack.is_empty() {
                stack.pop();
            } else {
                stack.push(byte);
            }
        }

        String::from_utf8_lossy(&stack).into_owned()
    }
}
