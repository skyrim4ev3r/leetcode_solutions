impl Solution {
    pub fn large_group_positions(s: String) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut left = 0_usize;

        for right in 0..len {
            if right == len - 1 || bytes[right] != bytes[right + 1] {
                if right - left + 1 > 2 {
                    res.push(vec![left as i32, right as i32]);
                }

                left = right + 1;
            }
        }

        res
    }
}
