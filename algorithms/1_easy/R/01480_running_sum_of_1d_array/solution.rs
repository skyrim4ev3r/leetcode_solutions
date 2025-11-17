impl Solution {
    pub fn running_sum(mut nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();

        for i in 1..len {
            nums[i] += nums[i - 1];
        }

        nums
    }
}
