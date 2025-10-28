impl Solution {
    pub fn minimum_sum_subarray(nums: Vec<i32>, l: i32, r: i32) -> i32 {
        let mut min_positive_sum = -1;
        let min_width = l as usize;
        let max_width = r as usize;
        let len = nums.len();

        for width in min_width..=max_width {
            let mut left = 0_usize;
            let mut right = width - 1;
            let mut sum = nums[left..=right].iter().sum::<i32>();

            while right < len {
                if sum > 0 && (sum < min_positive_sum || min_positive_sum == -1) {
                    min_positive_sum = sum;
                }

                right += 1;
                if right < len {
                    sum += nums[right];
                    sum -= nums[left];
                    left += 1;
                }
            }
        }

        min_positive_sum
    }
}
