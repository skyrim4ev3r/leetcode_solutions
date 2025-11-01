use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {

        let mut hashmap: HashMap<Vec<u8>, Vec<String>> = HashMap::new();
        let mut res:  Vec<Vec<String>> = Vec::new();

        for word in strs.into_iter() {
            let mut freqs = vec![0_u8; 26];

            for &byte in word.as_bytes() {
                freqs[(byte - b'a') as usize] += 1;
            }

            let mut freqs_pattern: Vec<u8> = Vec::new();

            for (index, freq) in freqs.into_iter().enumerate() {
                if freq > 0 {
                    freqs_pattern.push(b'a' + index as u8);

                    if freq > 1 {
                        freqs_pattern.extend(freq.to_string().into_bytes());
                    }
                }
            }

            hashmap.entry(freqs_pattern).or_insert(Vec::new()).push(word);
        }

        for (_, vec) in hashmap.into_iter() {
            res.push(vec);
        }

        res
    }
}
