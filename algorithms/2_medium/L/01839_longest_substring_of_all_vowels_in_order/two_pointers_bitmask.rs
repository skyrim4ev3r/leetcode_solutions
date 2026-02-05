impl Solution {
    pub fn longest_beautiful_substring(word: String) -> i32 {
        let bytes = word.as_bytes();
        let len = word.len();
        let mut left = 0_usize;
        let mut right = 0_usize;
        let mut longest = 0_usize;
        let mut word_mask = 0_u32;
        let vowel_mask = 1065233_u32; // zyxwvutsrqponmlkjihgfedcba
                                      // 00000100000100000100010001 => 1065233

        while right < len && left < len {
            if left < len && bytes[left] != b'a' {
                left += 1;
                word_mask = 0;
            } else {
                if right < left {
                    right = left;
                    word_mask = 0;
                }

                if right > left && bytes[right] < bytes[right - 1] {
                    left = right;
                    word_mask = 0;
                }

                let shift_amount = (bytes[right] - b'a');
                word_mask = (word_mask | (1 << shift_amount));

                if (word_mask & vowel_mask) == vowel_mask {
                    longest = longest.max(right - left + 1);
                }

                right += 1;
            }
        }

        longest as i32
    }
}
