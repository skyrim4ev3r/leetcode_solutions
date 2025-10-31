impl Solution {
    pub fn add_binary(a: String, b: String) -> String {

        let mut carry = 0_u8;
        let mut a_bytes = a.into_bytes();
        let mut b_bytes = b.into_bytes();

        if a_bytes.len() < b_bytes.len() {
            std::mem::swap(&mut a_bytes, &mut b_bytes);
        }

        let a_bytes_len = a_bytes.len();

        for i in (0..a_bytes_len).rev() {

            let mut b_byte = b'0';

            if let Some(byte) = b_bytes.pop() {
                b_byte = byte;
            }

            let mut bit_sum = (a_bytes[i] - b'0') + (b_byte - b'0') + carry;
            carry = 0;
            if bit_sum > 1 {
                bit_sum -= 2;
                carry = 1;
            }

            a_bytes[i] = bit_sum + b'0';

            if carry == 0 && b_bytes.is_empty() {
                break;
            }
        }

        if carry == 1 {
            a_bytes.insert(0_usize, b'1');
        }

        String::from_utf8(a_bytes).unwrap()
    }
}
