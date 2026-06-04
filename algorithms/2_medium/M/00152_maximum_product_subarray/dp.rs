impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut prev_max = 1_i32;
        let mut prev_min = 1_i32;
        let mut max_prod = i32::MIN;

        for num in nums.into_iter() {
            let curr_min = num.min(num * prev_min).min(num * prev_max);
            let curr_max = num.max(num * prev_min).max(num * prev_max);

            max_prod = max_prod.max(curr_max);
            prev_max = curr_max;
            prev_min = curr_min;
        }

        max_prod
    }
}
