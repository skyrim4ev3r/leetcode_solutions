impl Solution {
    pub fn minimum_one_bit_operations(mut n: i32) -> i32 {
        let mut res = 0_i32;
        let mut curr_index = 0_u32;

        while n > 0 {
            if n % 2 == 1 {
                res = 2_i32.pow(curr_index + 1) - 1 - res;
            }

            n /= 2;
            curr_index += 1;
        }

        res
    }
}
