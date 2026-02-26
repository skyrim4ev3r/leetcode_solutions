impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        let bytes = s.as_bytes();
        let flags_len = 2_usize.pow(k as u32);
        if (bytes.len() < flags_len + k as usize - 1) {
            return false;
        }
        let mut seen = vec![false; flags_len];
        let mask = 2_usize.pow(k as u32) - 1;
        let mut curr_index = 0_usize;
        bytes.iter().take(k as usize - 1).for_each(|&byte| curr_index = (curr_index << 1) | (byte - b'0') as usize);

        for byte in bytes.iter().skip(k as usize - 1) {
            curr_index = mask & ((curr_index << 1) | (byte - b'0') as usize);
            seen[curr_index] = true;
        }

        seen.into_iter().all(|flag| flag)
    }
}
