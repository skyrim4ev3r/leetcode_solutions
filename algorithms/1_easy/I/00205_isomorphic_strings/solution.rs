impl Solution {
    const TABLE_SIZE: usize = 256;
    const UNSEEN: isize = -1;

    pub fn is_isomorphic(s: String, t: String) -> bool {
        let s_bytes = s.as_bytes();
        let t_bytes = t.as_bytes();

        if s_bytes.len() != t_bytes.len() {
            return false;
        }

        let len = s_bytes.len();
        let mut s_first_seen = [-1_isize; Self::TABLE_SIZE];
        let mut t_first_seen = [-1_isize; Self::TABLE_SIZE];

        for i in 0..len {
            let ch_s_idx = s_bytes[i] as usize;
            let ch_t_idx = t_bytes[i] as usize;

            if s_first_seen[ch_s_idx] == -1 {
                s_first_seen[ch_s_idx] = i as isize;
            }

            if t_first_seen[ch_t_idx] == -1 {
                t_first_seen[ch_t_idx] = i as isize;
            }

            if s_first_seen[ch_s_idx ] != t_first_seen[ch_t_idx] {
                return false;
            }
        }

        true
    }
}
