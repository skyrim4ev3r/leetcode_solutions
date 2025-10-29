impl Solution {
    pub fn maximum_gap(mut nums: Vec<i32>) -> i32 {

        nums.sort_unstable();

        let mut max = 0_i32;

        for i in 1..nums.len() {
            max = max.max(nums[i] - nums[i - 1]);
        }

        max
    }
}
