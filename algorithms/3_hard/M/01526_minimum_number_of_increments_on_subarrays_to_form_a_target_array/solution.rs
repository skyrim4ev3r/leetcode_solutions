impl Solution {
    pub fn min_number_operations(target: Vec<i32>) -> i32 {
        target[0] + target.windows(2).into_iter().fold(0_i32, |acc, nums| acc + (nums[1] - nums[0]).max(0_i32))
    }
}
