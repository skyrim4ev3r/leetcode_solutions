impl Solution {

    #[inline(always)]
    fn count_subarrays_at_max(nums: &Vec<i32>, at_max: i32) -> i32 {
        let mut count = 0_i32;
        let mut crr_len = 0_i32;

        for &num in nums.iter() {
            if num > at_max {
                crr_len = 0;
            } else {
                crr_len += 1;
            }

            count += crr_len;
        }

        count
    }

    pub fn num_subarray_bounded_max(nums: Vec<i32>, max_lower_bound: i32, max_upper_bound: i32) -> i32 {
        Self::count_subarrays_at_max(&nums, max_upper_bound) - Self::count_subarrays_at_max(&nums, max_lower_bound - 1)
    }
}
