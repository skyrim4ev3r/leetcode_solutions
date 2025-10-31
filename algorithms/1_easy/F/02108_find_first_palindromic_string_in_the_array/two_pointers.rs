impl Solution {
    pub fn first_palindrome(words: Vec<String>) -> String {
        for word in words.into_iter() {
            let word_bytes = word.as_bytes();
            let mut right = word_bytes.len() - 1;
            let mut left = 0_usize;

            while left < right {
                if word_bytes[left] != word_bytes[right] {
                    break;
                }

                left += 1;
                right -= 1;
            }

            if left >= right {
                return word;
            }
        }

        "".to_string()
    }
}
