impl Solution {
    pub fn get_concatenation(mut nums: Vec<i32>) -> Vec<i32> {
        nums.iter().map(|x| *x).cycle().take(nums.len() * 2).collect::<Vec<i32>>()
    }
}
