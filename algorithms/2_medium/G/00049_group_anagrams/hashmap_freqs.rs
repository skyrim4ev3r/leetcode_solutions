use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {

        let mut map: HashMap<Vec<u8>, usize> = HashMap::new();
        let mut res:  Vec<Vec<String>> = Vec::new();

        for word in strs.into_iter() {

            let mut freqs = vec![0_u8; 26];

            for &byte in word.as_bytes() {
                freqs[(byte - b'a') as usize] += 1;
            }

            if let Some(val) = map.get(&freqs) {
                res[*val].push(word);
            } else {
                map.insert(freqs, res.len());
                res.push(vec![word]);
            }
        }

        res
    }
}
