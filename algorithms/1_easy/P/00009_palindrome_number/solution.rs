impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }

        let mut reversed = 0_i64;
        let mut tmp = x as i64;

        while tmp > 0 {
            reversed = reversed * 10 + tmp % 10;
            tmp /= 10;
        }

        reversed == x as i64
    }
}
