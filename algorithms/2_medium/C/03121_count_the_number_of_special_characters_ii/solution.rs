impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let mut lower = 0_u32;
        let mut upper = 0_u32;
        let mut lower_after_upper = 0_u32;

        for &byte in word.as_bytes().iter() {
            if byte >= b'a' && byte <= b'z' {
                let bit = 1_u32 << (byte - b'a') as u32;
                lower |= bit;

                if (upper & bit) != 0 {
                    lower_after_upper |= bit;
                }
            } else if byte >= b'A' && byte <= b'Z' {
                let bit = 1_u32 << (byte - b'A') as u32;
                upper |= bit;
            }
        }

        (lower & upper & (!lower_after_upper)).count_ones() as i32
    }
}