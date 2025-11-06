use std::collections::HashSet;

impl Solution {
    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        let mut allowed_bytes: [bool; 26] = [false; 26];
        allowed.into_bytes().into_iter().for_each(|byte| allowed_bytes[(byte - b'a') as usize] = true);
        let mut count = 0_i32;

        for word in words.into_iter() {
            let mut is_good = true;

            for byte in word.as_bytes().iter() {
                if !allowed_bytes[(byte - b'a') as usize] {
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
