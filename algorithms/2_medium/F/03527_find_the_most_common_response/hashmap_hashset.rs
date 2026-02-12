use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn find_common_response(responses: Vec<Vec<String>>) -> String {
        let mut words_count: HashMap<&str, i32> = HashMap::new();

        for response in responses.iter() {
            let mut unique_words_in_response: HashSet<&str> = HashSet::new();

            for word in response.into_iter() {
                if unique_words_in_response.insert(word.as_str()) {
                    *words_count.entry(word.as_str()).or_insert(0) += 1;
                }
            }
        }

        words_count.into_iter()
                   .max_by(|a, b| a.1.cmp(&b.1).then_with(|| b.0.cmp(&a.0)))
                   .unwrap()
                   .0
                   .to_string()
    }
}
