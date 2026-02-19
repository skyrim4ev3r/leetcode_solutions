use std::collections::HashMap;

impl Solution {
    pub fn prefix_connected(words: Vec<String>, k: i32) -> i32 {
        let mut hashmap: HashMap<&[u8], bool> = HashMap::new();
        let k_usize = k as usize;

        for w in words.iter() {
            if w.len() >= k_usize {
                *hashmap.entry(&w.as_bytes()[..k_usize]).and_modify(|val| *val = true).or_insert(false);
            }
        }

        hashmap.into_iter().filter(|(_, val)| *val == true).count() as i32
    }
}
