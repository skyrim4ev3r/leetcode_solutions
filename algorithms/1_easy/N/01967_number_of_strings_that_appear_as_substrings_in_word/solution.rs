impl Solution {
    pub fn num_of_strings(patterns: Vec<String>, word: String) -> i32 {
        let mut count = 0_i32;

        for pattern in patterns.into_iter() {
            if word.contains(&pattern) {
                count += 1;
            }
        }

       count
    }
}
