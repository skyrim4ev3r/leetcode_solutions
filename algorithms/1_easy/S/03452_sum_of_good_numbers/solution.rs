impl Solution {
    pub fn sum_of_good_numbers(nums: Vec<i32>, k: i32) -> i32 {
        let mut sum = 0_i32;
        let len = nums.len();
        let k_usize = k as usize;
    
        for i in 0..len {
            if (
                (i < k_usize || nums[i - k_usize] < nums[i]) &&
                (i + k_usize >= len || nums[i + k_usize] < nums[i])
            ) {
                sum += nums[i];
            }
        }

        sum
    }
}
