impl Solution {
    pub fn count_digits(num: i32) -> i32 {
        let mut num_cp = num;
        let mut count = 0_i32;

        while num_cp > 0 {
            let dig = num_cp % 10;
            num_cp /= 10;

            if dig == 0 {
                continue;
            }

            if num % dig == 0 {
                count += 1;
            }
        }

        count
    }
}
