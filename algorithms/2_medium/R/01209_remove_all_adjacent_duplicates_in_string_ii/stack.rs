impl Solution {
    pub fn remove_duplicates(s: String, k: i32) -> String {
        let mut stack: Vec<(u8, i32)> = Vec::new();

        for &byte in s.as_bytes() {
            if let Some((top_byte, top_freq)) = stack.last_mut() && *top_byte == byte {
                *top_freq += 1;

                if *top_freq == k {
                    stack.pop();
                }
            } else {
                    stack.push((byte, 1));
            }
        }

        let mut res: Vec<u8> = Vec::new();

        for (byte, freq) in stack.into_iter() {
            for _ in 0..freq {
                res.push(byte);
            }
        }

        String::from_utf8(res).unwrap()
    }
}
