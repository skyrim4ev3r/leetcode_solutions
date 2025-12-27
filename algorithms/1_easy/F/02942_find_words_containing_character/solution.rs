impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();

        for (i, word) in words.iter().enumerate() {
            if word.contains(x) {
                res.push(i as i32);
            }
        }

        res
    }
}
