impl Solution {
    pub fn smallest_palindrome(mut s: String) -> String {       
        let mut s_bytes = s.into_bytes();
        let mut freqs = [0_i32; 26];

        s_bytes.iter().for_each(|&byte| freqs[(byte - b'a') as usize] += 1);

        let mut left = 0_usize;
        let mut right = s_bytes.len() - 1;

        for (index, freq) in freqs.into_iter().enumerate() {
            let curr_char = index as u8 + b'a';
            // Input is valid, so if freq of any char be odd
            // then string len is also odd, and this char will be only char with odd freq
            if (freq & 1) == 1 {
                let mid = s_bytes.len() / 2;
                s_bytes[mid] = curr_char;
            }

            for _ in 0..(freq / 2) {
                s_bytes[left] = curr_char;
                s_bytes[right] = curr_char;
                left += 1;
                right -= 1;
            }
        }

        String::from_utf8_lossy(&s_bytes).into_owned()
    }
}
