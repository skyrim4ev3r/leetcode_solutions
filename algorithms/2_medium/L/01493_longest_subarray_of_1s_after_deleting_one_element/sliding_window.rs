impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {

        let mut left = 0_usize;
        let mut zero_count = 0_usize;
        let mut max_subarr_len = 0_usize;
        let len = nums.len();

        for right in 0..len {
            if nums[right] == 0 {
                zero_count += 1;
            }

            while zero_count > 1 {
                if nums[left] == 0 {
                    zero_count -= 1;
                }

                left += 1;
            }

            max_subarr_len = max_subarr_len.max(right - left + 1 - zero_count);
        }

        // Edge case: if entire arr is 1, then max_subarr_len will be equal to len
        // need to delete at least one of them
        if max_subarr_len == len {
            return max_subarr_len as i32 - 1;
        }

        max_subarr_len as i32
    }
}
