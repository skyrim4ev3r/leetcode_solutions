impl Solution {
    pub fn array_sign(nums: Vec<i32>) -> i32 {
        let mut res = 1_i32;

        for num in nums.into_iter() {
            if num == 0 {
                return 0;
            }

            if num < 0 {
                res *= -1;
            }
        }

        res
    }
}
