impl Solution {
    pub fn trailing_zeroes(n: i32) -> i32 {
        let mut cnt_five = 0_i32;
        let mut div = 5_i32;

        while div <= n {
            cnt_five += n / div;
            div *= 5;
        }

        cnt_five
    }
}
