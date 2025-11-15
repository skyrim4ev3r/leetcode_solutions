impl Solution {
    pub fn max_product(mut n: i32) -> i32 {
        let mut max1 = 0_i32;
        let mut max2 = 0_i32;

        while n > 0 {
            let digit = n % 10;
            n /= 10;

            if digit > max1 {
                max2 = max1;
                max1 = digit;
            } else {
                max2 = max2.max(digit);
            }
        }

        max1 * max2
    }
}
