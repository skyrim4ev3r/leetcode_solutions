impl Solution {
    pub fn min_removal(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();

        let len = nums.len();
        let mut left = 0_usize;
        let k = k as i64;
        let mut max_window = 0_usize;

        for right in 0..len {
            // No need to use while
            // Using 'if' to keep window size as max_window
            if (nums[left] as i64) * k < (nums[right] as i64) {
                left += 1;
            }

            max_window = max_window.max(right - left + 1);
        }

        (len - max_window) as i32
    }
}
