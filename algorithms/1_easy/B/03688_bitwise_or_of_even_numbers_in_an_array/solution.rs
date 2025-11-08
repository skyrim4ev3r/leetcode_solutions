
impl Solution {
    pub fn even_number_bitwise_o_rs(nums: Vec<i32>) -> i32 {
        nums.into_iter().filter(|&num| (num & 1) == 0).fold(0, |acc, num| acc | num)
    }
}
