impl Solution {
    pub fn has_increasing_subarrays(nums: Vec<i32>, k: i32) -> bool {

        let k_usize = k as usize;
        let mut left = 0_usize;
        let mut right = 2 * k_usize - 1;
        let len = nums.len();
        let mut breakpoint = 0_usize;
        let mut step = 0_usize;

        while (right < len) {
            let mut is_increasing = true;

            for i in (left + 1)..=right {
                if i == left + k_usize {
                    continue;
                }

                if nums[i - 1] >= nums[i] {
                    is_increasing = false;
                    breakpoint = i;
                    break;
                }
            }

            if (is_increasing) {
                return true;
            }

            if left + k_usize < breakpoint {
                step = breakpoint - left - k_usize;
            } else {
                step = breakpoint - left;
            }

            left += step;
            right += step; 
        }

        false
    }
}
