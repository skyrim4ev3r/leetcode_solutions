impl Solution {
    pub fn sort_string(s: String) -> String {
        let mut freqs = [0_u16; 26];
        let mut res: Vec<u8> = Vec::with_capacity(s.len());

        for byte in s.as_bytes().iter() {
            freqs[(*byte - b'a') as usize] += 1;
        }

        let mut flip_flop = true;
        while res.len() != s.len() {
            if flip_flop {
                for (i, freq) in freqs.iter_mut().enumerate() {
                    if (*freq > 0) {
                        *freq -= 1;
                        res.push(i as u8 + b'a');
                    }
                }
            } else {
                for (i, freq) in freqs.iter_mut().rev().enumerate() {
                    if (*freq > 0) {
                        *freq -= 1;
                        res.push(b'z' - i as u8);
                    }
                }
            }

            flip_flop = !flip_flop;
        }

        String::from_utf8(res).unwrap()
    }
}
