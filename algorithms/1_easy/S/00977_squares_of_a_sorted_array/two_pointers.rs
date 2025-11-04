impl Solution {
    pub fn sorted_squares(mut nums: Vec<i32>) -> Vec<i32> {
        for num in nums.iter_mut() {
            *num *= *num;
        }

        let nums_len = nums.len();
        let mut left = 0_usize;
        let mut right = nums_len - 1;
        let mut res = vec![0_i32; nums_len];
        let mut res_index = nums_len - 1;

        while left <= right {
            if nums[left] < nums[right] {
                res[res_index] = nums[right];
                right -= 1;
            } else {
                res[res_index] = nums[left];
                left += 1;
            }

            res_index -= 1;
        }

        res
    }
}
