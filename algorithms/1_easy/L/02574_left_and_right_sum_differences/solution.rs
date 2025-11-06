impl Solution {
    pub fn left_right_difference(nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();
        let mut res = vec![0_i32; len];

        let mut sum = 0_i32;
        for i in 0..len {
            res[i] += sum;
            sum += nums[i];
        }

        sum = 0;
        for i in (0..len).rev() {
            res[i] = (res[i] - sum).abs();
            sum += nums[i];
        }

        res
    }
}
