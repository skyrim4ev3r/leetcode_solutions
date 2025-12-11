impl Solution {
    pub fn min_moves2(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let len = nums.len();
        let median = nums[len / 2];

        nums.iter().map(|x| (*x - median).abs()).sum::<i32>()
    }
}
