impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut bytes = s.into_bytes();
        let len = bytes.len();
        let mut left = 0_usize;
        let mut write_idx = 0_usize;

        loop {
            while left != len && bytes[left] == b' ' {
                left += 1;
            }

            if left == len {
                break;
            }

            let mut right = left;
            while right != len && bytes[right] != b' ' {
                right += 1;
            }

            bytes[left..right].reverse();

            if write_idx > 0 {
                bytes[write_idx] = b' ';
                write_idx += 1;
            }

            while left != right {
                bytes[write_idx] = bytes[left];
                left += 1;
                write_idx += 1;
            }
        }

        bytes.truncate(write_idx);
        bytes.reverse();

        String::from_utf8(bytes).unwrap()
    }
}
