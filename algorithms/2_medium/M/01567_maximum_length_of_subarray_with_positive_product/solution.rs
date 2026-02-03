impl Solution {
    #[inline(always)]
    fn calc_subarray_score(
        nums: &Vec<i32>,
        start: usize,
        end: usize,
        negative_count: i32,
    ) -> i32 {
        if (negative_count & 1) == 0 {
            return (end - start) as i32;
        }

        let mut left = start;
        let mut right = end - 1;

        while nums[left] > 0 {
            left += 1;
        }

        while nums[right] > 0 {
            right -= 1;
        }

        let max_width = (right - start).max(end - 1 - left);

        max_width as i32
    }

    pub fn get_max_len(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut negative_count = 0_i32;
        let mut max_score = 0_i32;
        let mut left = 0_usize;
        let mut right = 0_usize;

        for &num in nums.iter() {
            if num < 0 {
                negative_count += 1;
            }

            if num == 0 {
                let curr_score = Self::calc_subarray_score(&nums, left, right, negative_count);

                max_score = max_score.max(curr_score);
                left = right + 1;
                negative_count = 0;
            }

            right += 1;
        }

        let curr_score = Self::calc_subarray_score(&nums, left, right, negative_count);
        max_score = max_score.max(curr_score);

        max_score
    }
}
