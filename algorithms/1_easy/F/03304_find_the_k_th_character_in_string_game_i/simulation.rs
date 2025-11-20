impl Solution {
    pub fn kth_character(k: i32) -> char {
        let k_usize = k as usize;
        let mut res = vec![b'a'];

        while res.len() < k_usize {
            let len = res.len();
            res.resize(2 * len, b' ');

            for i in 0..len {
                res[i + len] = res[i] + 1;
            }
        }

        res[k_usize - 1] as char
    }
}
