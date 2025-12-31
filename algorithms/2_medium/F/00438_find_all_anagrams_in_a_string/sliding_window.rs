impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        if p.len() > s.len() {
            return Vec::new();
        }

        let p = p.as_bytes();
        let s = s.as_bytes();
        let p_len = p.len();
        let s_len = s.len();
        let mut freqs_window_s = [0_i32; 26];
        let mut freqs_p = [0_i32; 26];
        let mut res: Vec<i32> = Vec::new();

        for i in 0..p_len {
            freqs_p[(p[i] - b'a') as usize] += 1;
            freqs_window_s[(s[i] - b'a') as usize] += 1;
        }

        if freqs_window_s == freqs_p {
            res.push(0);
        }

        for i in 0..(s_len - p_len) {
            freqs_window_s[(s[i] - b'a') as usize] -= 1;
            freqs_window_s[(s[i + p_len] - b'a') as usize] += 1;

            if freqs_window_s == freqs_p {
                res.push((i + 1) as i32);
            }
        }

        res
    }
}
