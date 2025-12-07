impl Solution {
    pub fn sum_base(mut n: i32, k: i32) -> i32 {
        let mut res = 0_i32;

        while n > 0 {
            res += n % k;
            n = n / k;
        }

        res
    }
}
