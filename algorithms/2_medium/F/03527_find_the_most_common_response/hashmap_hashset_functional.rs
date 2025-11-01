use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn find_common_response(responses: Vec<Vec<String>>) -> String {
        responses.iter()
        .fold(HashMap::new(), |mut map, response| {
            for word in response.iter().collect::<HashSet<_>>() {
                *map.entry(word).or_insert(0) += 1;
            }
            map
        })
        .into_iter()
        .max_by(|a, b| a.1.cmp(&b.1).then_with(|| b.0.cmp(&a.0)))
        .unwrap().0.to_string()       
    }
}
