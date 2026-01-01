impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let mut seen_upper = [false; 26];
        let mut seen_lower = [false; 26];
        let mut count = 0_i32;

        for &byte in word.as_bytes().iter() {
            if byte >= b'A' && byte <= b'Z' {
                seen_upper[(byte - b'A') as usize] = true;
            } else {
                seen_lower[(byte - b'a') as usize] = true;
            }
        }

        for i in 0..26 {
            if seen_lower[i] && seen_upper[i] {
                count += 1;
            }
        }

        count
    }
}
