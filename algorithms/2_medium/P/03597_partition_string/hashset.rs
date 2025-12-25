use std::collections::HashSet;

impl Solution {
    pub fn partition_string(s: String) -> Vec<String> {
        let mut seen = HashSet::<&[u8]>::new();
        let mut res = Vec::<String>::new();
        let mut left = 0_usize;
        let bytes = s.as_bytes();
        let len = bytes.len();

        for right in 0..len {
            let slice = &bytes[left..=right];

            if seen.insert(slice) {
                res.push(String::from_utf8_lossy(slice).into_owned());
                left = right + 1;
            }
        }

        res
    }
}
