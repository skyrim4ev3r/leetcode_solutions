impl Solution {
    pub fn minimum_delete_sum(s1: String, s2: String) -> i32 {
        let (bytes1, bytes2) = if s1.len() > s2.len() { 
            (s1.as_bytes(), s2.as_bytes())
        } else { 
            (s2.as_bytes(), s1.as_bytes())
        };

        let (len1, len2) = (bytes1.len(), bytes2.len());

        let mut dp: Vec<i32> = Vec::with_capacity(2 * (len2 + 1));
        unsafe { dp.set_len(2 * (len2 + 1)); }
        let (mut curr, mut next) = dp.split_at_mut(len2 + 1);
        next[len2] = 0;

        for j in (0..len2).rev() {
            next[j] = next[j + 1] + bytes2[j] as i32;
        }

        for idx1 in (0..len1).rev() {
            curr[len2] = next[len2] + bytes1[idx1] as i32;

            for idx2 in (0..len2).rev() {
                if bytes1[idx1] == bytes2[idx2] {
                    curr[idx2] = next[idx2 + 1];
                } else {
                    curr[idx2] = (curr[idx2 + 1] + bytes2[idx2] as i32)
                                 .min(next[idx2] + bytes1[idx1] as i32);
                }
            }

            (curr, next) = (next, curr);
        }

        next[0]
    }
}
