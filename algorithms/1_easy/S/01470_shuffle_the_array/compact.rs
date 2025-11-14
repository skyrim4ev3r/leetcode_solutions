impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        (0..n as usize).flat_map(|i| vec![nums[i], nums[i + n as usize]]).collect()
    }
}
