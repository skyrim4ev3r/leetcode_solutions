impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {

        let mut left = 0_usize;
        let mut right = nums.len() - 1;
        let mut min_val = i32::MAX;

        while left <= right {
            let mid = (right + left) / 2;

            if nums[left] <= nums[mid] {
                min_val = min_val.min(nums[left]);
                left = mid + 1;
            } else {
                min_val = min_val.min(nums[mid]);
                right = mid - 1;
            }
        }

        min_val
    }
}
