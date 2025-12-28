impl Solution {
    pub fn mirror_distance(n: i32) -> i32 {
        let mut temp = n;
        let mut rev_n = 0_i32;

        while temp > 0 {
            rev_n = rev_n * 10 + temp % 10;
            temp /= 10;
        }

        (n - rev_n).abs()
    }
}
