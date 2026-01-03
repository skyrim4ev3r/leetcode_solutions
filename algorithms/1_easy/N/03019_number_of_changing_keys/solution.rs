impl Solution {
    pub fn count_key_changes(s: String) -> i32 {
        let mut count = 0_i32;
        let bytes = s.as_bytes();
        let len = bytes.len();

        #[inline(always)]
        fn to_lower(byte: &u8) -> u8 {
            if *byte >= b'A' && *byte <= b'Z' {
                return *byte + 32;
            }

            *byte
        }

        for i in 1..len {
            if to_lower(&bytes[i]) != to_lower(&bytes[i - 1]) {
                count += 1;
            }
        }

        count
    }
}
