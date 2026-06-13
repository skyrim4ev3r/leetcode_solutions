impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        debug_assert!(ransom_note.len() <= i32::MAX as usize && magazine.len() <= i32::MAX as usize);
        let mut freqs = [0_i32; 26];

        for &byte in magazine.as_bytes() {
            debug_assert!(byte >= b'a' && byte <= b'z');
            freqs[(byte - b'a') as usize] += 1;
        }

        for &byte in ransom_note.as_bytes() {
            debug_assert!(byte >= b'a' && byte <= b'z');
            let freq = &mut freqs[(byte - b'a') as usize];

            if *freq == 0 {
                return false;
            }

            *freq -= 1;
        }

        true
    }
}
