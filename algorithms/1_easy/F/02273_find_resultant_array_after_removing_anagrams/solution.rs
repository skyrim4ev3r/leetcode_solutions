impl Solution {
    pub fn remove_anagrams(words: Vec<String>) -> Vec<String> {

        let mut res: Vec<String> = Vec::new();
        let mut prev_bytes: Vec<u8> = Vec::new();

        for word in words.into_iter() {
            let mut word_bytes = word.clone().into_bytes();
            word_bytes.sort_unstable();
            if prev_bytes != word_bytes {
                res.push(word);
                prev_bytes = word_bytes;
            }
        }

        res
    }
}
