impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut curr_max = 1_i32;
        let mut curr_min = 1_i32;
        let mut max_prod = i32::MIN;

        for num in nums.into_iter() {
            (curr_min, curr_max) = (
                num.min(num * curr_min).min(num * curr_max),
                num.max(num * curr_min).max(num * curr_max),
            );

            max_prod = max_prod.max(curr_max);
        }

        max_prod
    }
}
