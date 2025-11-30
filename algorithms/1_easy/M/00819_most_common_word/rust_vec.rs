use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn most_common_word(paragraph: String, banned: Vec<String>) -> String {
        let mut curr_bytes: Vec<u8> = Vec::new();
        let banned_set = banned.into_iter().map(|w| w.into_bytes()).collect::<HashSet<_>>();
        let mut freqs: HashMap<Vec<u8>, i32> = HashMap::new();

        for byte in paragraph.as_bytes().iter() {
            if *byte >= b'a' && *byte <= b'z' {
                curr_bytes.push(*byte);
            } else if *byte >= b'A' && *byte <= b'Z' {
                curr_bytes.push(*byte + 32_u8);
            } else {
                if curr_bytes.len() > 0 && !banned_set.contains(&curr_bytes) {
                    *freqs.entry(curr_bytes).or_insert(0) += 1;
                    curr_bytes = Vec::new();
                }

                curr_bytes.clear();
            }
        }

        if curr_bytes.len() > 0 && !banned_set.contains(&curr_bytes) {
            *freqs.entry(curr_bytes).or_insert(0) += 1;
        }

        let mut res: Vec<u8> = Vec::new();
        let mut max_freq = 0;

        for (bytes, freq) in freqs.into_iter() {
            if freq > max_freq {
                res = bytes;
                max_freq = freq;
            }
        }

        String::from_utf8(res).unwrap()
    }
}
