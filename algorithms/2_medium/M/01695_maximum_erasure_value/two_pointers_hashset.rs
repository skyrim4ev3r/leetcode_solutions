use std::collections::HashSet;

impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let mut hashset: HashSet<i32> = HashSet::new();
        let mut max_sum = 0_i32;
        let mut curr_sum = 0_i32;
        let mut left = 0_usize;
        let len = nums.len();

        for right in 0..len {
            let num = nums[right];

            while hashset.contains(&num) {
                hashset.remove(&nums[left]);
                curr_sum -= nums[left];
                left += 1;
            }

            curr_sum += num;
            hashset.insert(num);
            max_sum = max_sum.max(curr_sum);
        }

        max_sum
    }
}
