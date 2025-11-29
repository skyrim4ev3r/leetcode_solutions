impl Solution {
    pub fn clear_digits(s: String) -> String {
        let mut stack: Vec<u8> = Vec::new();

        for byte in s.as_bytes().iter() {
            if let Some(top) = stack.last() && (
                (*byte >= b'0' && *byte <= b'9') &&
                !(*top >= b'0' && *top <= b'9')
            ) {
                stack.pop();
            } else {
                stack.push(*byte);
            }
        }

        String::from_utf8(stack).unwrap()
    }
}
