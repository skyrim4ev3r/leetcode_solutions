impl Solution {
    pub fn largest_odd_number(num: String) -> String {
        let bytes = num.into_bytes();
        let len = bytes.len();
        let mut right_index = len - 1;

        while right_index < len && ((bytes[right_index] - b'0') & 1) == 0 {
            right_index -= 1;
        }

        if right_index > len {
            return "".to_string();
        }

        String::from_utf8_lossy(&bytes[..right_index + 1]).into_owned()
    }
}
