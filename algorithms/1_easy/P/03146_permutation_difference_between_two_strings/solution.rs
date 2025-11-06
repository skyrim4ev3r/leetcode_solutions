impl Solution {
    pub fn find_permutation_difference(s: String, t: String) -> i32 {

        let s_bytes = s.into_bytes();
        let t_bytes = t.into_bytes();
        let len = s_bytes.len();
        let mut position_diff = [0_i32; 26];
        
        for i in 0..len {
            position_diff[(s_bytes[i] - b'a') as usize] -= i as i32;
            position_diff[(t_bytes[i] - b'a') as usize] += i as i32;
        }

        position_diff.into_iter().map(|n| n.abs()).sum()
    }
}
