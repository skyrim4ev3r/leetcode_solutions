use std::collections::HashSet;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, target: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut hashset: HashSet<i32> = HashSet::new();

        for i in 0..len {
            if nums[i] != target[i] {
                hashset.insert(nums[i]);
            }
        }

        hashset.len() as i32
    }
}
