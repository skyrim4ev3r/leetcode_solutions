impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        let bytes1 = num1.as_bytes();
        let bytes2 = num2.as_bytes();

        if bytes1 == b"0" || bytes2 == b"0" {
            return "0".to_string();
        }

        let len1 = bytes1.len();
        let len2 = bytes2.len();
        let mut res: Vec<u8> = Vec::with_capacity(len1 + len2);

        for i in 0..len1 {
            let mut carry = 0_u8;

            for j in 0..len2 {
                let pos = i + j;

                if pos >= res.len() {
                    res.push(0_u8);
                }

                let curr_val = (bytes1[len1 - 1 - i] - b'0') * (bytes2[len2 - 1 - j] - b'0') + carry + res[pos];
                res[pos] =  curr_val % 10;
                carry = curr_val / 10;
            }

            if carry > 0 {
                res.push(carry);
            }
        }

        for byte in res.iter_mut() {
            *byte += b'0';
        }

        res.reverse();

        String::from_utf8(res).unwrap()
    }
}
