impl Solution {
    const FREQS_LEN: usize = 26;

    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut freqs = [0_i32; Self::FREQS_LEN];

        for (byte1, byte2) in s.into_bytes().into_iter().zip(t.into_bytes().into_iter()) {
            debug_assert!(byte1 >= b'a' && byte1 <= b'z');
            debug_assert!(byte2 >= b'a' && byte2 <= b'z');
            freqs[(byte1 - b'a') as usize] += 1;
            freqs[(byte2 - b'a') as usize] -= 1;
        }

        freqs.into_iter().all(|x| x == 0)
    }
}
