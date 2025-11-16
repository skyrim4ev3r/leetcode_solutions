impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut freqs_upper = [0_i32; 26];
        let mut freqs_lower = [0_i32; 26];

        for byte in s.as_bytes().iter() {
            if *byte >= b'a' && *byte <= b'z' {
                freqs_lower[(*byte -b'a') as usize] += 1;
            } else {
                freqs_upper[(*byte -b'A') as usize] += 1;
            }
        }

        let mut count = 0_i32;
        let mut any_odd = false;

        for freq in freqs_lower.iter() {
            if (*freq & 1) == 1 {
                count += *freq - 1;
                any_odd = true;
            } else {
                count += *freq;
            }
        }

        for freq in freqs_upper.iter() {
            if (*freq & 1) == 1 {
                count += *freq - 1;
                any_odd = true;
            } else {
                count += *freq;
            }
        }

        if any_odd {
            count += 1;
        }

        count
    }
}
