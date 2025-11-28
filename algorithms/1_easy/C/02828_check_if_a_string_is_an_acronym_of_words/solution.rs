impl Solution {
    pub fn is_acronym(words: Vec<String>, s: String) -> bool {
        if s.len() != words.len() {
            return false;
        }

        let s_bytes = s.as_bytes();

        for (i, word) in words.iter().enumerate() {
            if s_bytes[i] != word.as_bytes()[0] {
                return false;
            }
        }

        true
    }
}
