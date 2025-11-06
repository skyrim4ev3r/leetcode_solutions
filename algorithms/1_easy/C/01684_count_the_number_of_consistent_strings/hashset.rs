use std::collections::HashSet;

impl Solution {
    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        let allowed_bytes: HashSet<_> = allowed.into_bytes().into_iter().collect();
        let mut count = 0_i32;

        for word in words.into_iter() {
            let mut is_good = true;

            for byte in word.as_bytes().iter() {
                if !allowed_bytes.contains(byte) {
                    is_good = false;
                    break;
                }
            }

            if is_good {
                count += 1;
            }
        }

        count
    }
}
