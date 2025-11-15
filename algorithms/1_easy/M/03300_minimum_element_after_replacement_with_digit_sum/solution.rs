impl Solution {
    pub fn min_element(nums: Vec<i32>) -> i32 {
        let mut min = i32::MAX;

        for mut num in nums.into_iter() {
            let mut sum = 0_i32;

            while num > 0 {
                sum += num % 10;
                num /= 10;
            }

            min = min.min(sum);
        }

        min
    }
}
