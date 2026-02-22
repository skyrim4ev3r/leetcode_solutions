impl Solution {
    pub fn find_lhs(mut nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut left = 0_usize;
        let mut right = 0_usize;
        let mut longest = 0_usize;

        nums.sort_unstable();

        while right < len {
            while (nums[right] - nums[left] > 1) {
                left += 1;
            }

            while right + 1 < len && nums[right + 1] - nums[left] <= 1 {
                right += 1;
            }

            if nums[right] != nums[left] {
                longest = longest.max(right - left + 1);
            }

            right += 1;
        }

        longest as i32
    }
}
