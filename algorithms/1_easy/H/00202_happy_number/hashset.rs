use std::collections::HashSet;

impl Solution {
    pub fn is_happy(mut n: i32) -> bool {
        let mut hashset: HashSet<i32> = HashSet::new();

        loop {
            if n == 1 {
                return true;
            }

            if !hashset.insert(n) {
                return false;
            }

            let mut new_n = 0_i32;
            while n > 0 {
                new_n += (n % 10).pow(2);
                n /= 10;
            }
            n = new_n;
        }
    }
}
