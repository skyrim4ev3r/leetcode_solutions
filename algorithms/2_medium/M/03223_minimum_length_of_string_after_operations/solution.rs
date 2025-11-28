impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let mut freqs = [0_i32; 26];
        let mut count = 0_i32;

        for byte in s.as_bytes().iter() {
            freqs[(*byte - b'a') as usize] += 1;
        }

        for freq in freqs.into_iter() {
            if freq > 0 {
                if (freq & 1) == 1 {
                    count += 1;
                } else {
                    count += 2;
                }
            }
        }

        count
    }
}
