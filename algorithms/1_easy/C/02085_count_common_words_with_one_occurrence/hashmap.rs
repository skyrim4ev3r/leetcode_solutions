use std::collections::HashMap;

impl Solution {
    pub fn count_words(words1: Vec<String>, words2: Vec<String>) -> i32 {
        let mut freqs1: HashMap<&str, i32> = HashMap::new();
        let mut freqs2: HashMap<&str, i32> = HashMap::new();
        let mut count = 0_i32;

        for word in words1.iter() {
            *freqs1.entry(word).or_insert(0) += 1;
        }

        for word in words2.iter() {
            *freqs2.entry(word).or_insert(0) += 1;
        }

        for (word, freq1) in freqs1.iter() {
            if *freq1 == 1 {
                if let Some(freq2) = freqs2.get(word) && *freq2 == 1 {
                    count += 1;
                }
            }
        }

        count
    }
}
