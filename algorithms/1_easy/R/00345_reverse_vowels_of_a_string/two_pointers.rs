impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let mut s_bytes = s.into_bytes();
        let mut left = 0;
        let mut right = s_bytes.len() - 1;

        #[inline]
        fn is_vowel(ch: &u8) -> bool {
            match *ch {
                b'a' | b'e' | b'i' | b'o' | b'u' | b'A' | b'E' | b'I' | b'O' | b'U' => true,
                _ => false,
            }
        }

        loop {
            while left < right && !is_vowel(&s_bytes[right]) {
                right -= 1;
            }

            while left < right && !is_vowel(&s_bytes[left]) {
                left += 1;
            }

            if left >= right {
                break;
            }

            let temp = s_bytes[left];
            s_bytes[left] = s_bytes[right];
            s_bytes[right] = temp;

            right -= 1;
            left += 1;
        }

        String::from_utf8(s_bytes).unwrap()
    }
}
