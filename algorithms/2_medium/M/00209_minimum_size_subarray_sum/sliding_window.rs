impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut res_len =  len + 1;
        let mut left = 0_usize;
        let mut curr_sum = 0_i32;

        for right in 0..len {
            curr_sum += nums[right];

            while left <= right && curr_sum >= target {
                res_len = res_len.min(right - left + 1);
                curr_sum -= nums[left];
                left += 1;
            }
        }

        if res_len == len + 1 {
            return 0_i32;
        }

        res_len as i32
    }
}
