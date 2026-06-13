impl Solution {
    #[inline]
    fn is_vowel(byte: u8) -> bool {
        matches!(byte, b'a' | b'e' | b'i' | b'o' | b'u' | b'A' | b'E' | b'I' | b'O' | b'U')
    }

    pub fn reverse_vowels(s: String) -> String {
        let mut bytes = s.into_bytes();
        let mut lo = 0;
        let mut hi = bytes.len() as isize - 1;

        while lo < hi {
            while lo < hi && !Self::is_vowel(bytes[hi as usize]) {
                hi -= 1;
            }

            while lo < hi && !Self::is_vowel(bytes[lo as usize]) {
                lo += 1;
            }

            let temp = bytes[lo as usize];
            bytes[lo as usize] = bytes[hi as usize];
            bytes[hi as usize] = temp;

            hi -= 1;
            lo += 1;
        }

        String::from_utf8(bytes).unwrap()
    }
}
