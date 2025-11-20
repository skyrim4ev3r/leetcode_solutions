impl Solution {
    pub fn add_strings(num1: String, num2: String) -> String {
        let byte1 = num1.as_bytes();
        let byte2 = num2.as_bytes();
        let len1 = byte1.len();
        let len2 = byte2.len();
        let mut res: Vec<u8> = Vec::with_capacity(len1.max(len2) + 1);
        res.resize(len1.max(len2), b' ');

        let mut i1 = len1 - 1;
        let mut i2 = len2 - 1;
        let mut res_index = res.len() - 1;
        let mut carry = 0_u8;
        while i1 < len1 || i2 < len2 {
            let mut ch1 = 0_u8;
            if i1 < len1 {
                ch1 = byte1[i1] - b'0';
                i1 -= 1;
            }

            let mut ch2 = 0_u8;
            if (i2 < len2) {
                ch2 = byte2[i2] - b'0';
                i2 -= 1;
            }

            let mut sum = ch1 + ch2 + carry;
            carry = 0;
            if sum >= 10 {
                carry = 1;
                sum -= 10;
            }

            res[res_index] = sum + b'0';
            res_index -= 1;
        }

        if carry > 0 {
            res.resize(res.len() + 1, b' ');
            for j in (1..res.len()).rev() {
                res[j] = res[j - 1];
            }
            res[0] = carry + b'0';
        }

        String::from_utf8(res).unwrap()
    }
}
