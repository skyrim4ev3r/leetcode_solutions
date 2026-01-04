impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let nums_xor = nums.into_iter().fold(0_i32, |xor, num| xor ^ num);
        ((nums_xor - (nums_xor & k)).count_ones() + (k - (nums_xor & k)).count_ones()) as i32
    }
}
