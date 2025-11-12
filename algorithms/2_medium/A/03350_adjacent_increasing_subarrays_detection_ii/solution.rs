impl Solution {
    pub fn max_increasing_subarrays(nums: Vec<i32>) -> i32 {

        let mut max_adjacent_inc_len = 0_i32;
        let mut max_single_inc_len = 0_i32;
        let len = nums.len();
        let mut prev_inc_len = 0_i32;
        let mut curr_inc_len = 1_i32;

        for i in 1..len {
            if nums[i - 1] < nums[i] {
                curr_inc_len += 1;
            } else {
                max_adjacent_inc_len = max_adjacent_inc_len.max(curr_inc_len.min(prev_inc_len));
                max_single_inc_len = max_single_inc_len.max(curr_inc_len);
                prev_inc_len = curr_inc_len;
                curr_inc_len = 1;
            }
        }

        max_adjacent_inc_len = max_adjacent_inc_len.max(curr_inc_len.min(prev_inc_len));
        max_single_inc_len = max_single_inc_len.max(curr_inc_len);

        max_adjacent_inc_len.max(max_single_inc_len / 2)
    }
}
