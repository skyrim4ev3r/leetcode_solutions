impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {

        let min_word_len = strs.iter().map(|s| s.len()).min().unwrap_or(0);

        for word_index in 0..min_word_len {
            let byte = strs[0].as_bytes()[word_index];

            for word in strs.iter() {
                if word.as_bytes()[word_index] != byte {
                    return word[0..word_index].to_string()
                }
            }
        }

        strs[0][0..min_word_len].to_string()
    }
}
