impl Solution {
    pub fn count_even(num: i32) -> i32 {
        let mut count = 0_i32;

        for i in 1..=num {
            let mut temp = i;
            let mut dig_sum = 0;

            while temp > 0 {
                dig_sum += temp % 10;
                temp /= 10;
            }

            if (dig_sum & 1) == 0 {
                count += 1;
            }
        }

        count
    }
}
