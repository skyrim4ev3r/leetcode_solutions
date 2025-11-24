impl Solution {
    pub fn xor_operation(n: i32, start: i32) -> i32 {
        let mut res = 0_i32;

        for i in 0..n {
            res ^= (start + i * 2);
        }

        res
    }
}
