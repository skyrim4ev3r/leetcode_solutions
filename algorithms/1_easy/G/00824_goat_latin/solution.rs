impl Solution {

    #[inline(always)]
    fn is_vowel(byte: u8) -> bool {
        matches!(byte, b'a' | b'e' | b'i' | b'o' | b'u' | b'A' | b'E' | b'I' | b'O' | b'U')
    }

    pub fn to_goat_latin(sentence: String) -> String {
        let parts = sentence.split_whitespace().collect::<Vec<_>>();
        let mut end: Vec<u8> = Vec::with_capacity(parts.len() + 3);
        end.extend(b"maa");
        let mut res: Vec<u8> = Vec::with_capacity(
            sentence.len() +
            parts.len() * 2 + 
            (parts.len() * (parts.len() + 1)) / 2
        );

        for part in parts.iter() {
            let mut bytes: Vec<u8> = Vec::with_capacity(part.len() + end.len());
            bytes.extend_from_slice(part.as_bytes());

            if !Self::is_vowel(bytes[0]) {
                bytes.rotate_left(1);
            }

            bytes.extend_from_slice(&end);
            end.push(b'a');

            if !res.is_empty() {
                res.push(b' ')
            }

            res.extend(bytes);
        }

        String::from_utf8(res).unwrap()
    }
}
