impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        debug_assert!(len > 0);
        let sum = nums.iter().map(|x| *x).sum::<i32>();
        debug_assert!((len * (len + 1)) / 2 <= i32::MAX as usize);
        let target_sum = ((len * (len + 1)) / 2) as i32;

        target_sum - sum
    }
}
