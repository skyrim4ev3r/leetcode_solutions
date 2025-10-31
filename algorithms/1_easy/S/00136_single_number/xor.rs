impl Solution {
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut res = 0_i32;

        for num in nums.into_iter() {
            res ^= num;
        }

        res
    }
}
