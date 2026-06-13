impl Solution {
    const FREQS_LEN: usize = 26;

    pub fn find_the_difference(s: String, t: String) -> char {
       let mut freqs = [0_i32; Self::FREQS_LEN];

        for byte in s.into_bytes() {
            debug_assert!(byte >= b'a' && byte <= b'z');
            freqs[(byte - b'a') as usize] += 1;
        }

        for byte in t.into_bytes() {
            debug_assert!(byte >= b'a' && byte <= b'z');
            freqs[(byte - b'a') as usize] -= 1;
        }

        for (i, freq) in freqs.into_iter().enumerate() {
            if freq != 0 {
                return (i as u8 + b'a') as char;
            }
        }

        unreachable!("invalid input") 
    }
}
