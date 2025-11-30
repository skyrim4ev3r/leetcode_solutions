use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn most_common_word(paragraph: String, banned: Vec<String>) -> String {
        let mut curr_word = String::new();
        let banned_set = banned.into_iter().collect::<HashSet<String>>();
        let mut freqs: HashMap<String, i32> = HashMap::new();

        for ch in paragraph.chars() {
            match ch {
                ' ' | '!' | '?' | '\'' |',' | ';' | '.' => {
                    if curr_word.len() > 0 && !banned_set.contains(&curr_word) {
                        *freqs.entry(curr_word).or_insert(0) += 1;
                        curr_word = String::new();
                    }

                    curr_word .clear();
                },
                _ => curr_word.push(ch.to_lowercase().next().unwrap())
            } 
        }

        if curr_word.len() > 0 && !banned_set.contains(&curr_word) {
            *freqs.entry(curr_word.clone()).or_insert(0) += 1;
        }

        let mut res = String::new();
        let mut max_freq = 0;

        for (word, freq) in freqs.into_iter() {
            if freq > max_freq {
                res = word;
                max_freq = freq;
            }
        }

        res
    }
}
