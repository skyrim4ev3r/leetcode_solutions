use std::collections::HashMap;

impl Solution {
    pub fn min_deletion(s: String, k: i32) -> i32 {
        let mut freq: Vec<i32> = s.into_bytes().iter().fold(HashMap::new(), |mut acc, &ch| {
            *acc.entry(ch).or_insert(0) += 1;
            acc
        }).values().cloned().collect();

        freq.sort_unstable();

        freq.iter().rev().skip(k as usize).sum()
    }
}
