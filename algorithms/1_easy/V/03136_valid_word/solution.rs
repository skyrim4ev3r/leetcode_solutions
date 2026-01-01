impl Solution {
    #[inline]
    fn is_vowel(byte: u8) -> bool {
        match byte {
            b'a' | b'e' | b'i' | b'o' | b'u' => true,
            _ => false
        }
    }

    pub fn is_valid(word: String) -> bool {
        if word.len() < 3 {
            return false;
        }

        let mut has_vowel = false;
        let mut has_cons = false;

        for &byte in word.as_bytes().iter() {
            if byte >= b'A' && byte <= b'Z' {
                if Self::is_vowel(byte + 32) {
                    has_vowel = true;
                } else {
                    has_cons = true;
                }
            } else if byte >= b'a' && byte <= b'z' {
                if Self::is_vowel(byte) {
                    has_vowel = true;
                } else {
                    has_cons = true;
                }
            } else if byte >= b'0' && byte <= b'9' {
                continue;
            } else {
                return false;
            }
        }

        has_vowel && has_cons
    }
}
