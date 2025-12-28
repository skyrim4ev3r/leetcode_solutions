impl Solution {
    pub fn abs_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        let len = nums.len();

        if len == k as usize {
            return 0;
        }

        nums.sort_unstable();

        let sum_k_largest = nums[(len - k as usize)..].into_iter().sum::<i32>();
        let sum_k_smallet = nums[..k as usize].into_iter().sum::<i32>();

        (sum_k_largest - sum_k_smallet).abs()
    }
}
