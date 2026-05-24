impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let min_str_len = strs.iter().map(|s| s.len()).min().unwrap_or(0);

        for pos in 0..min_str_len {
            let byte = strs[0].as_bytes()[pos];

            for s in strs.iter() {
                if s.as_bytes()[pos] != byte {
                    return strs[0][0..pos].to_string();
                }
            }
        }

        strs[0][0..min_str_len].to_string()
    }
}
