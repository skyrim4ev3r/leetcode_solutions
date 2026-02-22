impl Solution {

    #[inline(always)]
    fn custom_transform(bytes: &[u8]) -> Vec<u8> {
        let mut curr_available = b'a';
        let mut byte_map = [0_u8; 26];
        let mut res: Vec<u8> = Vec::with_capacity(bytes.len());

        for byte in bytes.iter() {
            let byte_map_index = (*byte - b'a') as usize;

            if byte_map[byte_map_index] == 0 {
                byte_map[byte_map_index] = curr_available;
                curr_available += 1;
            }

            res.push(byte_map[byte_map_index]);
        }

        res
    }

    pub fn find_and_replace_pattern(words: Vec<String>, pattern: String) -> Vec<String> {
        let pattern_bytes_transformed = Self::custom_transform(pattern.as_bytes());
        let mut res: Vec<String> = Vec::new();

        for word in words.into_iter() {
            let word_bytes_transformed = Self::custom_transform(word.as_bytes());

            if word_bytes_transformed == pattern_bytes_transformed {
                res.push(word);
            }
        }

        res
    }
}
