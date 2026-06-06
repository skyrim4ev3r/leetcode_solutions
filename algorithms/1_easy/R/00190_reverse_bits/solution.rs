impl Solution {
    pub fn reverse_bits(n: i32) -> i32 {
        let mut res = 0_u32;
        let mut num = n as u32;

        for _ in 0..i32::BITS {
            res = (res << 1) | (num & 1);
            num >>= 1;
        }

        res as i32
    }
}
