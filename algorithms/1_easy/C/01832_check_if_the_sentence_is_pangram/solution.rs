use std::collections::HashSet;

impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        sentence.into_bytes().into_iter().collect::<HashSet<u8>>().len() == 26
    }
}
