impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let mut res = 0_i32;
        let mut stack: Vec<u8> = Vec::new();

        for byte in s.as_bytes().iter() {
            if *byte == b'a' {
                if let Some(top_byte) = stack.last() && *top_byte == b'b' {
                    stack.pop();
                    res += 1;
                } else {
                    stack.push(b'a');
                }
            } else {
                stack.push(b'b');
            }
        }

        res
    }
}
