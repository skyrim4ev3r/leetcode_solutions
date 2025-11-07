impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let mut count = 0_i32;

        for mut num in nums.into_iter() {
            let mut digit_count = 0_u8;

            while num > 0 {
                digit_count += 1;
                num /= 10;
            }

            if (digit_count & 1) != 1 {
                count += 1;
            }
        }

        count
    }
}
