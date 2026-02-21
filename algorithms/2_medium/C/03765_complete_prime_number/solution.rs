impl Solution {

    #[inline(always)]
    fn is_prime(num: i32) -> bool {
        if num == 2 {
            return true;
        }

        if num <= 1 || num % 2 == 0 {
            return false;
        }

        let sqrt_num = num.isqrt();

        for i in (3..=sqrt_num).step_by(2) {
            if num % i == 0 {
                return false;
            }
        }

        true
    }

    #[inline(always)]
    fn check_prefix(num: i32) -> bool {
        let mut prefix = num;
        while prefix > 0 {
            if !Self::is_prime(prefix) {
                return false;
            }

            prefix /= 10;
        }
        true
    }

    #[inline(always)]
    fn check_suffix(num: i32) -> bool {
        let mut suffix = num;
        let mut p = 1_i32;

        while suffix / p >= 10 {
            p *= 10;
        }

        while suffix > 0 {
            if !Self::is_prime(suffix) {
                return false;
            }

            suffix = suffix - (suffix / p) * p;
            p /= 10;
        }

        true
    }

    pub fn complete_prime(num: i32) -> bool {
        Self::check_prefix(num) && Self::check_suffix(num)
    }
}
