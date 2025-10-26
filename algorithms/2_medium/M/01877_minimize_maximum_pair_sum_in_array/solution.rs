impl Solution {
    pub fn min_pair_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();

        let mut left = 0_usize;
        let mut right = nums.len() - 1;
        let mut max_sum = 0_i32; //maximum sum of minimized pairs  

        while left < right {
            max_sum = max_sum.max(nums[left] + nums[right]);
            left += 1;
            right -= 1;
        }

        max_sum
    }
}
