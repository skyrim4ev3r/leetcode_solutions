impl Solution {
    pub fn magical_string(n: i32) -> i32 {
        if n <= 3 {
            return 1;
        }

        let target_len = n as usize;
        let mut bytes: Vec<u8> = Vec::with_capacity(target_len);
        bytes.extend_from_slice(b"122".as_slice());
        let mut index = 2_usize;
        let mut curr_byte = b'1';

        while bytes.len() < target_len {
            bytes.push(curr_byte);

            if bytes[index] == b'2' && bytes.len() < target_len {
                bytes.push(curr_byte);
            }

            curr_byte = if curr_byte == b'1' { b'2' } else { b'1' };
            index += 1;
        }

        bytes.into_iter().filter(|byte| *byte == b'1').count() as i32
    }
}
