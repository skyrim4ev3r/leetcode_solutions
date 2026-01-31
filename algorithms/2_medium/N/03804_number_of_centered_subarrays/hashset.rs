use std::collections::HashSet;

impl Solution {
    pub fn centered_subarrays(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut count = 0_i32;
        let mut hashset: HashSet<i32> = HashSet::with_capacity(len);

        for i in 0..len {
            let mut sum = 0;
            hashset.clear();

            for j in i..len {
                sum += nums[j];
                hashset.insert(nums[j]);

                if hashset.contains(&sum) {
                    count += 1;
                }
            }
        }

        count
    }
}
