impl Solution {
    pub fn make_good(s: String) -> String {
        let mut stack: Vec<u8> = Vec::new();

        for &byte in s.as_bytes().iter() {
            if let Some(&top) = stack.last() && (
                top + b'A' - b'a' == byte ||
                byte + b'A' - b'a' == top
            ) {
                stack.pop();
            } else {
                stack.push(byte);
            }
        }

        String::from_utf8(stack).unwrap()
    }
}
