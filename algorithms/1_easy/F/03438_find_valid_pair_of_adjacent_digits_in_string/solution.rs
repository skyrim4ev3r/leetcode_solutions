impl Solution {
    pub fn find_valid_pair(s: String) -> String {
        let mut freqs = [0_i32; 10];

        for byte in s.as_bytes().iter() {
            freqs[(*byte - b'0') as usize] += 1;
        }

        for w in s.as_bytes().windows(2) {
            if (
                w[0] != w[1] &&
                (w[0] - b'0') as i32 == freqs[(w[0] - b'0') as usize] &&
                (w[1] - b'0') as i32 == freqs[(w[1] - b'0') as usize]
            ) {
                return String::from_utf8_lossy(&w).into_owned();
            }
        }

        String::new()
    }
}
