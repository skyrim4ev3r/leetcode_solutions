impl Solution {
    const TABLE_SIZE: usize = 256;
    pub fn password_strength(password: String) -> i32 {
        let mut seen = [false; Self::TABLE_SIZE];

        for &byte in password.as_bytes() {
            seen[byte as usize] = true;
        }

        let mut score = 0_i32;

        for byte in 0..=u8::MAX {
            if seen[byte as usize] {
                score += match byte {
                    b'a'..=b'z' => 1,
                    b'A'..=b'Z' => 2,
                    b'0'..=b'9' => 3,
                    b'!' | b'@' | b'#' | b'$' => 5,
                    _ => 0,
                }
            }
        }

        score
    }
}
