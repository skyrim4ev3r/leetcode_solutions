impl Solution {
    pub fn last_non_empty_string(s: String) -> String {
        let bytes = s.as_bytes();
        let mut freqs = [0_i32; 26];

        for byte in bytes.iter() {
            freqs[(*byte - b'a') as usize] += 1;
        }

        let max = *freqs.iter().max().unwrap();

        for freq in freqs.iter_mut() {
            *freq = (*freq - max + 1).max(0);
        }

        let mut res: Vec<u8> = Vec::with_capacity(26);

        for byte in bytes.iter().rev() {
            if freqs[(*byte - b'a') as usize] > 0 {
                freqs[(*byte - b'a') as usize] -= 1;
                res.push(*byte);
            }
        }

        res.reverse();

        String::from_utf8(res).unwrap()
    }
}
