impl Solution {
    pub fn max_distinct(s: String) -> i32 {
        let mut is_seen = [false; 26];

        for byte in s.as_bytes().iter() {
            is_seen[(*byte - b'a') as usize] = true;
        }

        is_seen.iter().filter(|x| **x == true).count() as i32
    }
}
