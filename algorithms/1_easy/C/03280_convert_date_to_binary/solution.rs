impl Solution {
    #[inline]
    fn add_i16_binary_vec(vec: &mut Vec<u8>, num: i16) {

        let mut is_leading_zero = true;

        for i in (0..16).rev() {
            let byte = ((num >> i) & 1) as u8 + b'0';

            if (is_leading_zero && byte == b'0') {
                continue;
            }

            is_leading_zero = false;

            vec.push(byte);
        }
    }

    pub fn convert_date_to_binary(date: String) -> String {

        let mut res: Vec<u8> = Vec::new();
        let mut is_first_byte = true;

        for part in date.split('-').into_iter() {

            if !res.is_empty() {
                res.push(b'-');
            }

            let num = part.parse::<i16>().unwrap();
            Self::add_i16_binary_vec(&mut res, num);
        }

        String::from_utf8(res).unwrap()
    }
}
