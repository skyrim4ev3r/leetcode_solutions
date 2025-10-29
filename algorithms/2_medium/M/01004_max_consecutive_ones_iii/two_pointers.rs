impl Solution {
    pub fn longest_ones(nums: Vec<i32>, k: i32) -> i32 {

        let mut left = 0_usize;
        let mut count_zeros = 0_i32;
        let mut max = 0_i32;
        let len = nums.len();

        for right in 0..len {
            if nums[right] == 0 {
                count_zeros += 1;
            }

            while count_zeros > k {
                if nums[left] == 0 {
                    count_zeros -= 1;
                }
                left += 1;
            }

            if left <= right {
                max = max.max((right - left + 1) as i32);
            }
        }

        max
    }
}
