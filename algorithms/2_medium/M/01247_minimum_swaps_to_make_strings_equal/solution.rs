impl Solution {
    pub fn minimum_swap(s1: String, s2: String) -> i32 {
        let (bytes1, bytes2) = (s1.as_bytes(), s2.as_bytes());
        let mut xy = 0_i32; // x in s1, y in s2
        let mut yx = 0_i32; // y in s1, x in s2
        let len = bytes1.len();

        for i in 0..len {
            if bytes1[i] == b'x' && bytes2[i] == b'y' {
                xy += 1;
            } else if bytes1[i] == b'y' && bytes2[i] == b'x' {
                yx += 1;
            }
        }

        if ((xy + yx) & 1) == 1 {
            return -1;
        }

        (xy / 2) + (yx / 2) + (xy & 1) + (yx & 1)
    }
}
