impl Solution {

    #[inline(always)]
    fn calc_wave_num(mut n: i32) -> i32 {
        if n < 100 {
            return 0;
        }

        let mut count = 0_i32;

        let mut c = n % 10;
        n /= 10;
        let mut b = n % 10;
        n /= 10;
        let mut a = n % 10;
        n /= 10;

        loop {
            if ((b > a && b > c) || (b < a && b < c)) {
                count += 1;
            }

            if n == 0 { 
                break;
            }

            c = b;
            b = a;
            a = n % 10;
            n /= 10;
        }

        count
    }

    pub fn total_waviness(num1: i32, num2: i32) -> i32 {
        let mut count = 0_i32;

        for i in num1..=num2 {
            count += Self::calc_wave_num(i);
        }

        count
    }
}
