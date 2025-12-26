impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let len = s.len();
        let mut last_seen = [len; 26];
        let mut res: Vec<i32> = Vec::new();
        let bytes = s.as_bytes();

        for (i, byte) in bytes.iter().enumerate() {
            last_seen[(*byte - b'a') as usize] = i;
        }

        let mut left = 0_usize;
        let mut target_right = 0_usize;

        for right in 0..len {
            target_right = target_right.max(last_seen[(bytes[right] - b'a') as usize]);

            if target_right == right {
                res.push((right - left) as i32 + 1);
                left = right + 1;
            }
        }

        res
    }
}
