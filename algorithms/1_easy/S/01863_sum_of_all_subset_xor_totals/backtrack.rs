impl Solution {
    fn backtrack(start: usize, nums: &Vec<i32>, parent_xor: i32) -> i32 {
        let mut sum = 0;
        for i in start..nums.len() {
            let curr_xor = parent_xor ^ nums[i];
            sum += curr_xor;
            sum += Self::backtrack(i + 1, nums, curr_xor);
        }

        sum
    }

    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        Self::backtrack(0, & nums, 0)
    }
}
