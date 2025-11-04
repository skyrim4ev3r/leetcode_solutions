impl Solution {
    pub fn decode_string(s: String) -> String {

        let mut current_strbyte: Vec<u8> = Vec::new();
        let mut multiplier = 0;
        let mut stack_multipliers: Vec<i32> = Vec::new();
        let mut stack_strbytes: Vec<Vec<u8>> = Vec::new();

        for byte in s.into_bytes() {

            if byte.is_ascii_digit() {
                multiplier = multiplier * 10 + (byte - b'0') as i32;
            } else if byte == b'[' {
                stack_multipliers.push(multiplier);
                stack_strbytes.push(current_strbyte.clone());
                multiplier = 0;
                current_strbyte.clear();
            } else if byte.is_ascii_lowercase() {
                current_strbyte.push(byte);
            } else {
                if let (Some(last_multiplier), Some(mut last_strbyte)) = (stack_multipliers.pop(), stack_strbytes.pop()) {
                    for _ in 0..last_multiplier {
                        last_strbyte.extend_from_slice(&current_strbyte);
                    }
                    current_strbyte = last_strbyte;
                }
            }
        }

        String::from_utf8(current_strbyte).expect("error")
    }
}

