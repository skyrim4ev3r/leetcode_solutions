impl Solution {
    fn solve(mem: &mut Vec<i32>, s: &[u8], len: usize, pos: usize) -> i32 {
        if pos == len {
            1
        } else if mem[pos] > -1 {
            mem[pos]
        } else if s[pos] == b'0' {
            mem[pos] = 0;
            0
        } else {
            let mut res = Self::solve(mem, s, len, pos + 1);
            if pos < s.len() - 1 && (s[pos] == b'1' || (s[pos] == b'2' && s[pos+1] < b'7')) {
                res += Self::solve(mem, s, len, pos + 2);
            }
            mem[pos] = res;

            res
        }
    }

    pub fn num_decodings(mut s: String) -> i32 {
        let mut mem = vec![-1i32; s.len()];

        Self::solve(&mut mem, s.as_bytes(), s.len(), 0)
    }
}

