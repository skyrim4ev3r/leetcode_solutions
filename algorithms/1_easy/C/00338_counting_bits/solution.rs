impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        debug_assert!(n >= 0);
        let mut res = vec![0; n as usize + 1];

        for i in 0..=n {
            res[i as usize] = res[(i >> 1) as usize] + (i & 1);
        }

        res
    }
}
