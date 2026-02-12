// 1- Sort array
// 2- Choose two largest and one smallest for each sub-array, and second largest will be median
// 3- Add 2nd largest to sum as median

impl Solution {
    pub fn maximum_median_sum(mut nums: Vec<i32>) -> i64 {
        nums.sort_unstable();
        nums.iter().rev().skip(1).step_by(2).take(nums.len() / 3).map(|&value| value as i64).sum()
    }
}
