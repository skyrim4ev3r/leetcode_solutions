impl Solution {

    #[inline]
    fn is_vowel(ch: &u8) -> bool {
        matches!(*ch, b'a' | b'e' | b'i' | b'o' | b'u' | b'A' | b'E' | b'I' | b'O' | b'U')
    }

    pub fn sort_vowels(mut s: String) -> String {
        let mut s_bytes = s.into_bytes();

        //inserting all vowel chars of current string into vector
        let mut vowels: Vec<u8> = s_bytes.iter().filter(|&ch| Self::is_vowel(ch)).cloned().collect();
        vowels.sort_unstable_by(|a, b| b.cmp(a)); // then sorting that vector

        for byte in s_bytes.iter_mut() {
            if Self::is_vowel(byte) {
                *byte = vowels.pop().unwrap();
            }
        }

        String::from_utf8_lossy(&s_bytes).into_owned()
    }
}
