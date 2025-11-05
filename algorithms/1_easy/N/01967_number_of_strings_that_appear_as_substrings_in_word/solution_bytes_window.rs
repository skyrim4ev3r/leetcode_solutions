impl Solution {
    pub fn num_of_strings(patterns: Vec<String>, word: String) -> i32 {

        let word_bytes = word.into_bytes();
        let mut count = 0_i32;

        for pattern in patterns.into_iter() {
            let pattern_bytes = pattern.into_bytes();
            let pattern_bytes_len = pattern_bytes.len();

            if word_bytes.windows(pattern_bytes_len).any(|window| window == pattern_bytes) {
                count += 1;
            }
        }

       count
    }
}
