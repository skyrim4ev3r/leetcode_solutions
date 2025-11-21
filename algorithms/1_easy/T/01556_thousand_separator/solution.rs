impl Solution {
    pub fn thousand_separator(mut n: i32) -> String {
        if n == 0 {
            return "0".to_string();
        }

        let mut res: Vec<u8> = Vec::with_capacity(13);
        let mut dig_count = 0_u8;

        while n > 0 {
            dig_count += 1;
            res.push((n % 10) as u8 + b'0');
            n /= 10;

            if n > 0 && dig_count % 3 == 0 {
                res.push(b'.');
            }
        }

        res.reverse();

        String::from_utf8(res).unwrap()
    }
}
