impl Solution {
    #[inline]
    fn is_vowel(byte: &u8) -> bool {
        match *byte {
            b'a' | b'e' | b'i' | b'o' | b'u' => true,
            _ => false,
        }
    }

    #[inline]
    fn count_vowels(word: &str) -> i32 {
        let mut count = 0_i32;

        for byte in word.as_bytes().iter() {
            if Self::is_vowel(byte) {
                count += 1;
            }
        }

        count
    }

    pub fn reverse_words(s: String) -> String {
        let mut res: Vec<u8> = Vec::with_capacity(s.len());
        let parts = s.split_whitespace().collect::<Vec<&str>>();
        let first_word_vowel_count = Self::count_vowels(parts[0]);
        res.extend_from_slice(parts[0].as_bytes());

        for part in parts.into_iter().skip(1) {
            let curr_vowel_count = Self::count_vowels(part);
            res.push(b' ');

            if curr_vowel_count == first_word_vowel_count {
                res.extend(part.as_bytes().iter().rev());
            } else {
                res.extend_from_slice(part.as_bytes());
            }
        }

        String::from_utf8(res).unwrap()
    }
}
