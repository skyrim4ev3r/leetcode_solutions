impl Solution {
    pub fn sum_indices_with_k_set_bits(nums: Vec<i32>, k: i32) -> i32 {

        let k = k as u32;
        let mut sum = 0_i32;
        let nums_len = nums.len();

        for i in 0..nums_len {
            if i.count_ones() == k {
                sum += nums[i];
            }
        }

        sum
    }
}
