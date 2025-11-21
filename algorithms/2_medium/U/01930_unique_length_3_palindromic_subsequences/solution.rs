impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut is_seen_first = [false; 26];
        let mut count = 0_i32;

        for i in 0..len {
            if !is_seen_first[(bytes[i] - b'a') as usize] {
                is_seen_first[(bytes[i] - b'a') as usize] = true;

                let mut k = len - 1;
                while k > i && bytes[k] != bytes[i] {
                    k -= 1;
                }

                let mut is_seen_second = [false; 26];

                for j in (i + 1)..k {
                    if !is_seen_second[(bytes[j] - b'a') as usize] {
                        count += 1;
                        is_seen_second[(bytes[j] - b'a') as usize] = true;
                    }
                }
            }
        }

        count
    }
}
