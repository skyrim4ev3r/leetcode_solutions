impl Solution {
    fn to_custom_base(mut num: i32, base: i32) -> String {
        if num == 0 {
            return String::from("0");
        }

        let mut res: Vec<u8> = Vec::new();

        while num > 0 {
            let remainder = num % base;
            if remainder < 10 {
                res.push(remainder as u8 + b'0')
            } else {
                res.push(remainder as u8 -10 + b'A')
            }

            num /= base;
        }

        res.reverse();

        String::from_utf8(res).unwrap()
    }

    pub fn concat_hex36(n: i32) -> String {
        format!("{:X}{}", n * n, Self::to_custom_base(n * n * n, 36))
    }
}
