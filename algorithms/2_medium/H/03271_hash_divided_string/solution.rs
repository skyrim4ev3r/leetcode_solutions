impl Solution {
    pub fn string_hash(s: String, k: i32) -> String {
        let old_len = s.len();
        let new_len = (old_len + k as usize - 1) / k as usize;
        let mut new_bytes: Vec<u8> = Vec::with_capacity(new_len);
        let mut count = 0_i32;
        let mut sum = 0_i32;

        for (i, byte) in s.as_bytes().iter().enumerate() {
            count += 1;
            sum += (*byte - b'a') as i32;

            if count == k || i == old_len - 1 {
                count = 0;
                new_bytes.push((sum % 26) as u8 + b'a');
                sum = 0;
            }
        }

        String::from_utf8(new_bytes).unwrap()
    }
}
