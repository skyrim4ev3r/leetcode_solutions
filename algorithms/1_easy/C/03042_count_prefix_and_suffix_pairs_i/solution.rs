impl Solution {
    pub fn count_prefix_suffix_pairs(words: Vec<String>) -> i32 {
        let mut count = 0;
        let len = words.len();

        for i in 0..len {
            for j in (i + 1)..len {
                if words[j].starts_with(&words[i]) && words[j].ends_with(&words[i]) {
                    count += 1;
                }
            }
        }

        count
    }
}
