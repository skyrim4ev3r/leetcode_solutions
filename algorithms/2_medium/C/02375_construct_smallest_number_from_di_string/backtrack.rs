impl Solution {
    fn backtrack(
        res: &mut[u8],
        pattern: &[u8],
        curr_idx: usize,
        seen: u32,
        res_ready: &mut bool,
    ) {
        if curr_idx == res.len() { 
            *res_ready = true;
            return;
        }
        
        for i in 1..=9_u8 {
            let mask = 1_u32 << i;
            if (seen & mask) == 0 {
                if curr_idx > 0 && pattern[curr_idx - 1] == b'I' && (res[curr_idx - 1] - b'0') > i {
                    continue;
                }

                if curr_idx > 0 && pattern[curr_idx - 1] == b'D' && (res[curr_idx - 1] - b'0') < i {
                    break;
                }

                res[curr_idx] = i as u8 + b'0';
                Self::backtrack(res, pattern, curr_idx + 1, seen | mask, res_ready);
            }

            if *res_ready {
                return;
            }
        }
    }

    pub fn smallest_number(pattern: String) -> String {
        assert!(pattern.len() <= 8);
        let mut res = vec![b' '; pattern.len() + 1];
        let mut res_ready = false;
        let mut seen = 0_u32;
        Self::backtrack(&mut res, pattern.as_bytes(), 0, seen, &mut res_ready);

        String::from_utf8(res).unwrap()
    }
}
