impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        if nums.iter().any(|&num| num != nums[0]) { 1 } else { 0 }
    }
}
