impl Solution {
    pub fn count_digit_occurrences(nums: Vec<i32>, digit: i32) -> i32 {
        let mut freq = 0_i32;

        for mut num in nums {
            while num > 0 {
                if num % 10 == digit {
                    freq += 1;
                }
                num /= 10;
            }
        }

        freq
    }
}
