impl Solution {
    pub fn min_subsequence(mut nums: Vec<i32>) -> Vec<i32> {

        nums.sort_unstable();

        let mut sum_left: i32 = nums.iter().sum();
        let mut sum_right = 0_i32;
        let mut index = nums.len() - 1;
        let mut res: Vec<i32> = Vec::new();

        while sum_left >= sum_right {
            sum_right += nums[index];
            sum_left -= nums[index];
            res.push(nums[index]);
            index -= 1;
        }

        res
    }
}
