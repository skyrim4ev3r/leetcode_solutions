impl Solution {
    pub fn minimum_cost(mut nums: Vec<i32>) -> i32 {
        nums[1..].sort_unstable();

        nums[..3].iter().map(|x| *x).sum::<i32>()
    }
}
