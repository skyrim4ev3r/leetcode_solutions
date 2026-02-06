impl Solution {
    #[inline(always)]
    fn find_smallest_index(nums: &Vec<i32>, len: usize) -> usize {
        let mut left = 0_usize;
        let mut right = len - 1;

        while left < right {
            let mid = left + (right - left) / 2;

            if nums[mid] == nums[left] && nums[mid] == nums[right] {
                left += 1;

                if nums[left - 1] > nums[left] {
                    return left;
                }
            } else if nums[mid] >= nums[left] {
                left = mid + 1;

                if nums[left - 1] > nums[left] {
                    return left;
                }
            } else {
                right = mid - 1;

                if nums[right] > nums[right + 1] {
                    return right + 1;
                }
            }
        }

        left
    }

    pub fn search(nums: Vec<i32>, target: i32) -> bool {
        let len = nums.len();        
        let min_index = Self::find_smallest_index(&nums, len);

        nums[..min_index].binary_search(&target).is_ok() ||
        nums[min_index..].binary_search(&target).is_ok()
    }
}
