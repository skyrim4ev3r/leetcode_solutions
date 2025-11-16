impl Solution {
    pub fn add_digits(mut num: i32) -> i32 {
        while num >= 10 {
            num = num % 10 + num / 10;
        }

        num
    }
}
