impl Solution {
    pub fn left_right_difference(mut nums: Vec<i32>) -> Vec<i32> {
        let mut sum_to_right = nums.iter().map(|x| *x).sum::<i32>();
        let mut sum_to_left = 0_i32;

        for num_ref in nums.iter_mut()  {
            let original_val = *num_ref;
            sum_to_right -= original_val;
            *num_ref = (sum_to_right - sum_to_left).abs();
            sum_to_left += original_val;
        }

        nums
    }
}
