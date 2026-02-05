use std::collections::HashMap;

impl Solution {
    pub fn count_pairs(words: Vec<String>) -> i64 {
        let mut freqs: HashMap<Vec<u8>, i32> = HashMap::new();

        for word in words.iter() {
            let bytes = word.as_bytes();
            let bytes_len = bytes.len();
            let mut adj_diff = vec![0_u8; bytes_len];
            adj_diff[0] = ((bytes[0] - b'a') as i8 - (bytes[bytes_len - 1] - b'a') as i8).rem_euclid(26) as u8;

            for i in 1..bytes_len {
                adj_diff[i] = ((bytes[i] - b'a') as i8 - (bytes[i - 1] - b'a') as i8).rem_euclid(26) as u8;
                            // Though code below work as well,
                            // but it working on top of underflow and overflow, because u8 wont be negative
                            // so its just nicer to use i8 and rem_euclid(26) instead of :
                            // ((bytes[i] - b'a') - (bytes[i - 1] - b'a') + 26) % 26;
            }

            *freqs.entry(adj_diff).or_insert(0) += 1;
        }

        let mut count = 0_i64;

        for (_, freq) in freqs.into_iter() {
            count += ((freq as i64) * (freq as i64 - 1)) / 2;
        }

        count
    }
}
