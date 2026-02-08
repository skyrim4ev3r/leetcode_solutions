impl Solution {
    pub fn reverse_str(s: String, k: i32) -> String {
        let mut bytes = s.into_bytes();
        let k_usize = k as usize;
        let len = bytes.len();

        for i in (0..len).step_by(2 * k_usize) {
            let start = i;
            let end = (i + k_usize).min(len);

            bytes[start..end].reverse();
        }

        String::from_utf8(bytes).unwrap()
    }
}
