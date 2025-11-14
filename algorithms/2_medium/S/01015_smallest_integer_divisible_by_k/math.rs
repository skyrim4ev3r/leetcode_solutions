use std::collections::HashSet;

impl Solution {
    pub fn smallest_repunit_div_by_k(k: i32) -> i32 {
        let mut prev_reminder = 1 % k;
        let mut seen: HashSet<i32> = HashSet::new();
        let mut curr_len = 1_i32;

        while prev_reminder != 0 {
            if !seen.insert(prev_reminder) {
                return -1;
            }

            prev_reminder = (prev_reminder * 10 + 1) % k;
            curr_len += 1;
        }

        curr_len
    }
}
