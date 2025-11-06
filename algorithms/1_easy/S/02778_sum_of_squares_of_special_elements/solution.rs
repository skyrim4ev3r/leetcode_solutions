impl Solution {
    pub fn sum_of_squares(nums: Vec<i32>) -> i32 {
        let mut res = 0_i32;
        let len = nums.len();
        let sqrt_len = (len as f64).sqrt() as usize;

        for i in 1..= sqrt_len {
            if len % i == 0 {
                let other_index = len / i;
                res += nums[i - 1].pow(2);

                if other_index != i {
                    res += nums[other_index - 1].pow(2);
                }
            }
        }

        res
    }
}
