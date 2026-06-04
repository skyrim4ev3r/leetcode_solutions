impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let mut left = 0_isize;
        let mut right = nums.len() as isize - 1;
        let mut min_val = i32::MAX;

        while left <= right {
            let mid = (right + left) / 2;

            if nums[left as usize] <= nums[mid as usize] {
                min_val = min_val.min(nums[left as usize]);
                left = mid + 1;
            } else {
                min_val = min_val.min(nums[mid as usize]);
                right = mid - 1;
            }
        }

        min_val
    }
}
