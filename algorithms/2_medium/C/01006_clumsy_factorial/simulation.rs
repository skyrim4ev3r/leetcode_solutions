impl Solution {
    pub fn clumsy(mut n: i32) -> i32 {
        let mut is_first = true;
        let mut res = 0_i32;

        while n > 0 {
            let mut curr = n;
            n -= 1;

            if n > 0 {
                curr *= n;
                n -= 1;
            }

            if n > 0 {
                curr /= n;
                n -= 1;
            }

            if is_first {
                res += curr;
                is_first = false;
            } else {
                res -= curr;
            }

            if n > 0 {
                res += n;
                n -= 1;
            }
        }

        res
    }
}
