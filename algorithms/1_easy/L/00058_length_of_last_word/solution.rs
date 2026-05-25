impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut curr_word_len = 0_i32;
        let mut last_word_len = 0_i32;

        for byte in s.as_bytes().iter() {
            if *byte == b' ' {
                curr_word_len = 0;
            } else {
                curr_word_len += 1;
                last_word_len = curr_word_len;
            }
        }

        last_word_len
    }
}
