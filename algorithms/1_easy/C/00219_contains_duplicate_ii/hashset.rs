use std::collections::HashSet;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let k_usize = k as usize;
        let mut hashset: HashSet<i32> = HashSet::new();

        for (i, num) in nums.iter().enumerate() {
            if i > k_usize {
                hashset.remove(&nums[i - k_usize - 1]);
            }

            if !hashset.insert(*num) {
                return true;
            }
        }

        false
    }
}
