impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let sum = nums.iter().map(|x| *x).sum::<i32>();
        let n = nums.len() as i32;
        let target_sum = n * (n + 1) / 2;

        target_sum - sum
    }
}
