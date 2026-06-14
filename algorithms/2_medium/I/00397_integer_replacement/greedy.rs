impl Solution {
    pub fn integer_replacement(n_i32: i32) -> i32 {
        debug_assert!(n_i32 > 0);
        let mut n = n_i32 as i64;
        let mut steps = 0;

        while n != 1 {
            if (n & 1) == 0 {
                n /= 2;
            } else if n != 3 && (n & 3) == 3 {
                n += 1;
            } else {
                n -= 1;
            }

            steps += 1;
        }

        steps
    }
}
