impl Solution {
    pub fn sum_of_the_digits_of_harshad_number(x: i32) -> i32 {

        let mut tmp = x;
        let mut dig_sum = 0;

        while tmp > 0 {
            dig_sum += tmp % 10;
            tmp /= 10;
        }

        if x % dig_sum != 0 {
            return -1;
        }

        dig_sum
    }
}
