impl Solution {
    pub fn min_flips(target: String) -> i32 {
        let mut prev_ch = b'0';
        let mut count = 0_i32;
        for ch in target.into_bytes().into_iter() {
            if ch != prev_ch {
                prev_ch = ch;
                count += 1;
            }
        }
        
        count
    }
}
