impl Solution {
    fn construct_largest_special(bytes: &[u8]) -> Vec<u8> {
        let len = bytes.len();
        if len <= 2 {
            return bytes.to_vec();
        }
        let mut left = 0_usize;
        let mut balance = 0_i32;
        let mut parts: Vec<Vec<u8>> = Vec::new();

        for right in 0..len {
            if bytes[right] == b'1' {
                balance += 1;
            } else {
                balance -= 1;
            }

            if balance == 0 {
                let mut temp: Vec<u8> = Vec::with_capacity(right - left + 1);
                temp.push(b'1');
                temp.extend(Self::construct_largest_special(&bytes[left + 1..right]));
                temp.push(b'0');
                parts.push(temp);
                left = right + 1;
            }
        }

        parts.sort_unstable_by(|a, b| b.cmp(&a));

        let mut res: Vec<u8> = Vec::with_capacity(len);

        for part in parts.into_iter() {
            res.extend(part);
        }

        res
    }

    pub fn make_largest_special(s: String) -> String {
        String::from_utf8(Self::construct_largest_special(s.as_bytes())).unwrap()
    }
}
