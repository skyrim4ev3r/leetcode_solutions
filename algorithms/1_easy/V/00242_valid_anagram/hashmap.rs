use std::collections::{HashMap,hash_map};

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {

        if (s.len() != t.len()) {
            return false;
        }

        let mut freqs: HashMap<u8, i32> = HashMap::new();

        for byte in s.into_bytes().into_iter() {
            *freqs.entry(byte).or_insert(0) += 1;
        }

        for byte in t.into_bytes() {
            match freqs.entry(byte) {
                hash_map::Entry::Occupied(mut entry) => {
                    let count = entry.get_mut();
                    *count -= 1;
                    if *count < 0 {
                        return false;
                    }
                },
                hash_map::Entry::Vacant(_) => {
                    return false;
                }
            }
        }

        true
    }
}
