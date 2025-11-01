impl Solution {
    pub fn triangle_number(mut nums: Vec<i32>) -> i32 {

        let mut sum = 0_usize;
        let len = nums.len();

        nums.sort_unstable();

        for i in 2..len {

            let mut left = 0_usize;
            let mut right = i - 1;

            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    // Add all triplets
                    // nums[left..=right - 1], nums[right], nums[i]
                    sum += right - left;
                    right -= 1;
                } else {
                    left += 1;
                }
            }
        }

        sum as i32
    }
}
