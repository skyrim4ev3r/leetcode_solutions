impl Solution {
    pub fn max_absolute_sum(nums: Vec<i32>) -> i32 {
        let mut min_sum = 0_i32;
        let mut max_sum = 0_i32;
        let mut curr_sum = 0_i32;

        for num in nums.into_iter() {
            curr_sum += num;
            min_sum = min_sum.min(curr_sum);
            max_sum = max_sum.max(curr_sum);
        }

        max_sum - min_sum
    }
}
