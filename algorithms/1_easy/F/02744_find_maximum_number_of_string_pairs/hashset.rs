use std::collections::HashSet;

impl Solution {
    pub fn maximum_number_of_string_pairs(words: Vec<String>) -> i32 {
        let mut hashset: HashSet<Vec<u8>> = HashSet::new();
        let mut count = 0_i32;

        for word in words.into_iter() {
            let bytes = word.into_bytes();
            let mut rev_bytes = bytes.clone();
            rev_bytes.reverse();

            if hashset.remove(&rev_bytes) {
                count += 1;
            } else {
                hashset.insert(bytes);
            }
        }

        count
    }
}
