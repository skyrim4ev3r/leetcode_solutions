impl Solution {
    pub fn maximize_sum(nums: Vec<i32>, k: i32) -> i32 {
        (nums.into_iter().max().unwrap()) * k + (k * (k - 1)) / 2
    }
}
