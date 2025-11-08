impl Solution {
    pub fn reverse_degree(s: String) -> i32 {
        s.as_bytes()
         .iter()
         .enumerate()
         .fold(0_i32, |acc, (index, byte)| acc + ((b'z' - *byte + 1) as i32) * (index + 1) as i32 )
    }
}
