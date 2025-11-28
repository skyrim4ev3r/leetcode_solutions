impl Solution {
    pub fn split_words_by_separator(words: Vec<String>, separator: char) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();

        for word in words.iter() {
            for part in word.split(separator) {
                if !part.is_empty() {
                    res.push(part.to_string());
                }
            }
        }

        res
    }
}
