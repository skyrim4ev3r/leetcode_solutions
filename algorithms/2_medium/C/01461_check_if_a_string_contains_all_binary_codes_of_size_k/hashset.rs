impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        s.into_bytes()
         .windows(k as usize)
         .map(|w| u32::from_str_radix(&String::from_utf8_lossy(w), 2).unwrap())
         .collect::<std::collections::HashSet<u32>>()
         .len() == 2_usize.pow(k as u32)
    }
}
