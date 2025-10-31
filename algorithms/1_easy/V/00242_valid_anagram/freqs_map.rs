impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {

        if (s.len() != t.len()) {
            return false;
        }

        const freqs_len: usize = 26_usize;
        let mut freqs = [0_i32; freqs_len];

        for byte in s.into_bytes().into_iter() {
            freqs[(byte - b'a') as usize] += 1;
        }

        for byte in t.into_bytes().into_iter() {
            let freqs_index = (byte - b'a') as usize;

            freqs[freqs_index] -= 1;

            if freqs[freqs_index] < 0 {
                return false;
            }
        }

        true
    }
}
