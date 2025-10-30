use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {

        let mut map: HashMap<Vec<u8>, usize> = HashMap::new();
        let mut res:  Vec<Vec<String>> = Vec::new();

        for word in strs.into_iter() {

            let word_bytes = word.into_bytes();
            let mut sorted_word: Vec<u8> = Vec::with_capacity(word_bytes.len());
            let mut freqs = [0_i32; 26];

            for &byte in word_bytes.iter() {
                freqs[(byte - b'a') as usize] += 1;
            }

            for i in 0..26_usize {
                let byte = i as u8 + b'a';
                for _ in 0..freqs[i] {
                    sorted_word.push(byte);
                }
            }

            if let Some(val) = map.get(&sorted_word) {
                res[*val].push(String::from_utf8(word_bytes).unwrap());
            } else {
                map.insert(sorted_word, res.len());
                res.push(vec![String::from_utf8(word_bytes).unwrap()]);
            }
        }

        res
    }
}
