impl Solution {
    pub fn integer_break(n: i32) -> i32 {
        if n == 2 {
            return 1;
        }

        if n == 3 {
            return 2;
        }

        let mut count_two = 0;
        let mut count_three = n / 3;
        let remainder = n % 3;

        if remainder == 1 {
            count_two = 2;
            count_three -= 1;
        } else if remainder == 2 {
            count_two = 1;
        }

        3_i32.pow(count_three as u32) * 2_i32.pow(count_two as u32)
    }
}
