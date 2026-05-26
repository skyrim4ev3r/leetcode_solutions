impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let bytes = word.as_bytes();
        let len = bytes.len();
        let mut flags = [0_u8; 26];

        for &byte in bytes.iter() {
            if byte >= b'a' && byte <= b'z' {
                flags[(byte - b'a') as usize] |= 1;
            } else {
                flags[(byte - b'A') as usize] |= 2;
            }
        }

        let mut count = 0_i32;

        for i in 0..26 {
            if flags[i] == 3 {
                count += 1;
            }
        }

        count
    }
}
