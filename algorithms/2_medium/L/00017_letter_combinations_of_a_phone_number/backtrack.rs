impl Solution {
    fn backtrack(
        res: &mut Vec<String>,
        digits_bytes: &[u8],
        map_digit_to_bytes: &[Vec<u8>],
        temp: &mut Vec<u8>,
        curr_idx: usize,
        digits_len: usize,
    ) {
        if curr_idx == digits_len {
            res.push(String::from_utf8_lossy(&temp).into_owned());
            return;
        }

        let num_to_chars_idx = (digits_bytes[curr_idx] - b'2') as usize;

        for &byte in map_digit_to_bytes[num_to_chars_idx].iter() {
            temp.push(byte);
            Self::backtrack(res, digits_bytes, map_digit_to_bytes, temp, curr_idx + 1, digits_len);
            temp.pop();
        }

    }
    
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let map_digit_to_bytes = [
            vec![b'a',b'b',b'c'],
            vec![b'd',b'e',b'f'],
            vec![b'g',b'h',b'i'],
            vec![b'j',b'k',b'l'],
            vec![b'm',b'n',b'o'],
            vec![b'p',b'q',b'r', b's'],
            vec![b't',b'u',b'v'],
            vec![b'w',b'x',b'y', b'z']
        ];

        let mut temp: Vec<u8> = Vec::new();
        let mut res: Vec<String> = Vec::new();
        let digits_bytes = digits.into_bytes();
        let digits_len = digits_bytes.len();

        Self::backtrack(&mut res, &digits_bytes, &map_digit_to_bytes, &mut temp, 0, digits_len);

        return res;
    }
}
