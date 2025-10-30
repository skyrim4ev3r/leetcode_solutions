use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {

        let mut map: HashMap<Vec<u8>, usize> = HashMap::new();
        let mut res:  Vec<Vec<String>> = Vec::new();

        for word in strs.into_iter() {

            let mut sorted_word = word.clone().into_bytes();
            sorted_word.sort_unstable();

            if let Some(val) = map.get(&sorted_word) {
                res[*val].push(word);
            } else {
                map.insert(sorted_word, res.len());
                res.push(vec![word]);
            }
        }

        res
    }
}
