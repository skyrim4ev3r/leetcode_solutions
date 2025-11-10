impl Solution {
    pub fn number_of_steps(mut num: i32) -> i32 {

        let mut count = 0_i32;

        while num > 0 {
            count += 1;
            if (num & 1) == 1 {
                num -= 1;
            } else {
                num /= 2;
            }
        }

        count
    }
}
