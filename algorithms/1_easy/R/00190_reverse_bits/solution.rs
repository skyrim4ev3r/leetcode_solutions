impl Solution {
    pub fn reverse_bits(mut n: i32) -> i32 {
        let mut res = 0i32;

        for i in 0..32 {
            res <<=1;
            res |= n & 1;
            n >>= 1;
        }

        res
    }
}
