impl Solution {
    pub fn max_frequency(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort_unstable();

        let mut curr_cost = 0_i64;
        let mut left = 0_usize;
        let mut max_width = 1_usize;
        let len = nums.len();
        let k_i64 = k as i64;

        for right in 1..len {
            let inc_amount = (nums[right] - nums[right - 1]) as i64;
            let count_prev_nums = (right - left) as i64;

            curr_cost += inc_amount * count_prev_nums;

            while curr_cost > k_i64 {
                curr_cost -= (nums[right] - nums[left]) as i64;
                left += 1;
            }

            max_width = max_width.max(right - left + 1);
        }

        max_width as i32
    }
}
