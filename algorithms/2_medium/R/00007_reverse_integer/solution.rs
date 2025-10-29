impl Solution {
    pub fn reverse(x: i32) -> i32 {

        let mut rev = 0_i64;
        let mut x_abs_i64 = (x as i64).abs();

        while x_abs_i64 != 0 {
            rev = rev * 10 + x_abs_i64 % 10;
            x_abs_i64 /= 10; 
        }

        if x < 0 {
            rev *= -1;
        }

        if rev > i32::MAX as i64 || rev < i32::MIN as i64 {
            return 0; 
        }

        rev as i32
    }
}
