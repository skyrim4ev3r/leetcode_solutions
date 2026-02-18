impl Solution {

    #[inline(always)]
    fn count_subarrays(nums: &Vec<i32>, start: usize, end: usize, max_lower_bound: i32) -> usize {
        if start == end {
            return 0;
        }

        let width = end - start;
        let total_possible_subarrays = width * (width + 1) / 2;
        let mut invalid_counts = 0_usize;
        let mut left = start;

        for right in start..end {
            if nums[right] >= max_lower_bound {
                let invalid_width = right - left;
                invalid_counts += (invalid_width * (invalid_width + 1)) / 2;
                left = right + 1;
            }
        }

        let invalid_width = end - left;
        invalid_counts += (invalid_width * (invalid_width + 1)) / 2;

        total_possible_subarrays - invalid_counts
    }

    pub fn num_subarray_bounded_max(nums: Vec<i32>, max_lower_bound: i32, max_upper_bound: i32) -> i32 {
        let len =  nums.len();
        let mut start = 0_usize;
        let mut count = 0_usize;

        for end in 0..len {
            if nums[end] > max_upper_bound {
                count += Self::count_subarrays(&nums, start, end, max_lower_bound);
                start = end + 1;
            }
        }

        count += Self::count_subarrays(&nums, start, len, max_lower_bound);

        count as i32
    }
}
