impl Solution {
    #[inline(always)]
    fn calc_product_digits(mut n: i32) -> i32 {
        let mut res = 1_i32;

        while n > 0 {
            res = res * (n % 10);
            n /= 10;
        }

        res
    }

    pub fn smallest_number(n: i32, t: i32) -> i32 {     
        // In every 10 consecutive numbers, at least one has the digit 0,
        // ensuring a product of 0, which satisfies the condition 0 % t == 0.
        for i in n..(n + 10) {
            let product_digits = Self::calc_product_digits(i);

            if product_digits % t == 0 {
                return i;
            }
        }

        unreachable!()
    }
}
