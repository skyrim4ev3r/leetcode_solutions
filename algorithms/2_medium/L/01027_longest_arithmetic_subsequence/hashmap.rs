use std::collections::HashMap;

impl Solution {
    pub fn longest_arith_seq_length(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if len <= 2 { return len as i32; }

        let mut dp = vec![HashMap::new(); len];
        let mut res = 0;

        for i in (0..len).rev() {
            for j in ((i + 1)..len).rev() {
                let diff = nums[i] - nums[j];
                let prev = *dp[j].get(&diff).unwrap_or(&1);
                let curr = prev + 1;
                let entry = dp[i].entry(diff).or_insert(0);
                *entry = (*entry).max(curr);
                res = res.max(curr);
            }
        }

        res
    }
}
