impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut count = 0_i32;

        for byte in s.as_bytes().into_iter().rev() {
            if *byte != b' ' {
                count += 1;
            } else if count != 0 {
                return count;
            }
        }

        count
    }
}
