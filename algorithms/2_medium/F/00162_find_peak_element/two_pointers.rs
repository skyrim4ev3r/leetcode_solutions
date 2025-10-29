impl Solution {
    pub fn find_peak_element(nums: Vec<i32>) -> i32 {

        let mut right = nums.len() - 1;
        let mut left = 0_usize;

        while left < right {
            let mid = (left + right) / 2;

            if nums[mid] > nums[mid + 1] {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left as i32
    }
}
