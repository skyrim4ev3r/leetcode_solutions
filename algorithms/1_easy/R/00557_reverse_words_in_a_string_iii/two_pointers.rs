impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut bytes = s.into_bytes();
        let len = bytes.len();
        let mut left = 0_usize;

        while left < len {
            let mut right = left;
            while right < len - 1 && bytes[right + 1] != b' ' {
                right += 1;
            }

            let next_index_for_left = right + 2;

            while left < right {
                let temp = bytes[left];
                bytes[left] = bytes[right];
                bytes[right] = temp;

                right -= 1;
                left += 1;
            }

            left = next_index_for_left;
        }

        String::from_utf8(bytes).unwrap()
    }
}
