impl Solution {
    pub fn is_substring_present(s: String) -> bool {
        let mut seen = [[false; 26]; 26];

        for w in s.as_bytes().windows(2) {
            let i = (w[0] - b'a') as usize;
            let j = (w[1] - b'a') as usize;

            seen[i][j] = true;

            if seen[j][i] {
                return true;
            }
        }

        false
    }
}
