impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let mut count = 0_i32;
        let mut curr_max = nums[0];

        for num in nums.into_iter().skip(1) {
            if (num <= curr_max) {
                curr_max += 1;
                count += curr_max - num;
            } else {
                curr_max = num;
            }
        }

        count
    }
}
