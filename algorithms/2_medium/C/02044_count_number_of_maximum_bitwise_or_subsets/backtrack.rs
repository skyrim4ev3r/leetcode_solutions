impl Solution {
    fn subsets_backtrack(nums: &Vec<i32>, max_or: i32, curr_or: i32, start_index: usize, count: &mut i32) {
        if curr_or == max_or {
            *count += 2_i32.pow((nums.len() - start_index) as u32);
            return;
        }
        for i in start_index..nums.len() {
            Self::subsets_backtrack(&nums, max_or, curr_or | nums[i], i + 1, count);
        }
    }
    pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
        let max_or = nums.iter().fold(0, |or, num| or | num);
        let mut count = 0;
        Self::subsets_backtrack(&nums, max_or, 0, 0, &mut count);

        count
    }
}
