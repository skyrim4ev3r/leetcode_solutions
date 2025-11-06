impl Solution {
    pub fn has_increasing_subarrays(nums: Vec<i32>, k: i32) -> bool {

        let k_usize = k as usize;
        let window_len = 2 * k_usize;

        for window in nums.windows(window_len) {
            let mut is_increasing = true;

            for i in 1..window_len {
                if i == k_usize {
                    continue;
                }

                if window[i - 1] >= window[i] {
                    is_increasing = false;
                    break;
                }
            }

            if is_increasing {
                return true;
            }
        }

        false
    }
}
