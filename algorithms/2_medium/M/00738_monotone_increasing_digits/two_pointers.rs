impl Solution {
    #[inline(always)]
    fn get_digits(mut n: i32) -> Vec<i32> {
        let mut digits: Vec<i32> = Vec::with_capacity(10);

        while n > 0 {
            digits.push(n % 10);
            n /= 10;
        }

        digits.reverse();

        digits
    }

    pub fn monotone_increasing_digits(n: i32) -> i32 {
        if n < 10 {
            return n;
        }

        let digits = Self::get_digits(n);
        let len = digits.len();
        let mut res = 0_i32;
        let mut left = 0_usize;
        let mut right = 0_usize;

        while right < len {
            if digits[right] == digits[left] {
                right += 1;
            } else if digits[right] > digits[left] {
                while left < right {
                    res *= 10;
                    res += digits[left];
                    left += 1;
                }
            } else {
                res *= 10;
                res += digits[left] - 1;
                left += 1;

                while left < len {
                    res *= 10;
                    res += 9;
                    left += 1;
                }

                return res;
            }
        }

        // If 'right' reach end, then it means n has monotone increasing digits
        // So simply returning n is enough
        n
    }
}
