impl Solution {
    pub fn detect_capital_use(word: String) -> bool {
        let bytes = word.as_bytes();
        let mut is_lower = bytes[0] >= b'a' && bytes[0] <= b'z';
        let mut is_upper = !is_lower;
        let mut is_capital = is_upper;

        for byte in bytes.iter().skip(1) {
            if *byte >= b'a' && *byte <= b'z' {
                is_upper = false;
            } else {
                is_capital = false;
                is_lower = false;
            }

            if !is_capital && !is_lower && !is_upper {
                return false;
            }
        }

        true
    }
}
