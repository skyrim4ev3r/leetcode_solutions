impl Solution {
    pub fn generate_key(num1: i32, num2: i32, num3: i32) -> i32 {
        let mut p = 1_i32;
        let mut res = 0_i32;

        while p <= num1 && p <= num2 && p <= num3 {
            p *= 10;
        }
        p /= 10;

        while p > 0 {
            let curr_min_dig = ((num1 / p) % 10)
                                .min((num2 / p) % 10)
                                .min((num3 / p) % 10);

            p /= 10;
            res *= 10;
            res += curr_min_dig;
        }

        res
    }
}
