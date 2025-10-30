impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {

        let len = nums.len();
        let mut right = len - 1;
        let mut left = 0;

        while left <= right && left < len && right < len {
            let mid = (left + right) / 2;
            if nums[mid] == target {
                return mid as i32;
            }
            
            if nums[left] <= nums[mid] {
                if target <= nums[mid] && target >= nums[left] {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if target <= nums[right] && target >= nums[mid] {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        -1
    }
}
