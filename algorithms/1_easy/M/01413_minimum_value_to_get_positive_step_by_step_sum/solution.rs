impl Solution {
    pub fn min_start_value(nums: Vec<i32>) -> i32 {
        let mut min_sum = i32::MAX;
        let mut curr_sum = 0_i32;

        for num in nums.iter() {
            curr_sum += *num;
            min_sum = min_sum.min(curr_sum);
        }

        1_i32.max(min_sum * -1 + 1)
    }
}
