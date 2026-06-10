use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut freqs: HashMap<u8, i32> = HashMap::new();;

        for (byte1, byte2) in s.into_bytes().into_iter().zip(t.into_bytes().into_iter()) {
            debug_assert!(byte1 >= b'a' && byte1 <= b'z');
            debug_assert!(byte2 >= b'a' && byte2 <= b'z');
            *freqs.entry(byte1).or_insert(0) += 1;
            *freqs.entry(byte2).or_insert(0) -= 1;
        }

        freqs.into_iter().all(|(_, freq)| freq == 0)
    }
}
