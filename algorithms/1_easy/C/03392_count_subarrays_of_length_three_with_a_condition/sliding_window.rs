impl Solution {
    pub fn count_subarrays(nums: Vec<i32>) -> i32 {

        let mut count = 0_i32;

        for window in nums.windows(3) {
            if (window[1] & 1) == 0 && (window[0] + window[2]) == window[1] / 2 {
                count += 1;
            }
        }

        count
    }
}
