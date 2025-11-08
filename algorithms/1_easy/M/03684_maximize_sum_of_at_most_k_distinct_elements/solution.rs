use std::collections::BTreeSet;
impl Solution {
    pub fn max_k_distinct(nums: Vec<i32>, k: i32) -> Vec<i32> {
        nums.into_iter().collect::<BTreeSet<i32>>().into_iter().rev().take(k as usize).collect::<Vec<i32>>()
    }
}
