impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i64 {
        let mut max1 = 0_i32;
        let mut max2 = 0_i32;

        for num in nums.into_iter() {
            let abs_num = num.abs();

            if abs_num > max1 {
                max2 = max1;
                max1 = abs_num;
            } else if abs_num > max2 {
                max2 = abs_num;
            }
        }

        (max1 as i64) * (max2 as i64) * 100_000_i64
    }
}
