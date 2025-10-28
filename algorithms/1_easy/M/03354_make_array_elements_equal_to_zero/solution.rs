impl Solution {
    pub fn count_valid_selections(nums: Vec<i32>) -> i32 {
        let mut sum_right = nums.iter().sum::<i32>();
        let mut sum_left = 0_i32;
        let mut count = 0_i32;

        for num in nums.into_iter() {
            sum_left += num;
            sum_right -= num;

            if num == 0 {
                if sum_left == sum_right {
                    count += 2;
                } else if (sum_left - sum_right).abs() == 1 {
                    count += 1;
                }
            }
        }

        count
    }
}
