impl Solution {
    pub fn convert_to_base7(mut num: i32) -> String {
        if num==0 {
            return "0".to_string();
        }

        let mut digits: Vec<u8> = Vec::new();
        let mut is_negative = num < 0;
        num = num.abs();

        while num > 0 {
            digits.push((num % 7) as u8 + '0' as u8);
            num /= 7;
        }

        if is_negative {
            digits.push('-' as u8);
        }

        digits.reverse();

        String::from_utf8(digits).unwrap()
    }
}
