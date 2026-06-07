impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        debug_assert!(nums.len() > 0);
        debug_assert!(target > 0);

        let len = nums.len();
        let mut min_width =  len + 1;
        let mut left = 0_usize;
        let mut curr_sum = 0_i32;

        for right in 0..len {
            debug_assert!(nums[right] > 0);
            debug_assert!(i32::MAX - nums[right] >= curr_sum);
            curr_sum += nums[right];

            while left <= right && curr_sum >= target {
                min_width = min_width.min(right - left + 1);
                curr_sum -= nums[left];
                left += 1;
            }
        }

        if min_width == len + 1 { 0 } else { min_width as i32 }
    }
}
