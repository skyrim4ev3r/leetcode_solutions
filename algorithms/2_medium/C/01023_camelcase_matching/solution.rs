impl Solution {
    #[inline(always)]
    fn match_result(q: &[u8], p: &[u8]) -> bool {
        let len_q = q.len();
        let len_p = p.len();
        let mut i_q = 0;
        let mut i_p = 0;

        while i_q < len_q && i_p < len_p {
            if q[i_q] == p[i_p] {
                i_p += 1;
            } else if q[i_q] >= b'A' && q[i_q] <= b'Z' {
                return false;
            }

            i_q += 1;
        }

        if i_p != len_p {
            return false;
        }

        while i_q < len_q {
            if q[i_q] >= b'A' && q[i_q] <= b'Z' {
                return false;
            }

            i_q += 1;
        }

        true
    }

    pub fn camel_match(queries: Vec<String>, pattern: String) -> Vec<bool> {
        let mut res: Vec<bool> = Vec::with_capacity(queries.len());

        for q in queries.into_iter() {
            res.push(Self::match_result(q.as_bytes(), pattern.as_bytes()));
        }

        res
    }
}
