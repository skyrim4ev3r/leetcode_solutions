use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn find_common_response(responses: Vec<Vec<String>>) -> String {
        let mut words_count: HashMap<&String, i32> = HashMap::new();
        for response in responses.iter() {
            let mut unique_words_in_response: HashSet<&String> = HashSet::new();

            for word in response.into_iter() {
                if unique_words_in_response.insert(&word) {
                    *words_count.entry(&word).or_insert(0) += 1;
                }
            }
        }

        let mut max_freq = 0_i32;
        let mut max_str = &String::new();
        for (word, freq) in words_count.into_iter() {
            if freq > max_freq {
                max_freq = freq;
                max_str = word;
            } else if freq == max_freq && word < max_str {
                max_str = word;
            }
        }

        max_str.clone()     
    }
}
