impl Solution {
    pub fn to_hex(num: i32) -> String {
        if num == 0 {
            return "0".to_string();
        }

        let mut u_num = num as u32;
        let mut res: Vec<u8> = Vec::new();

        while u_num > 0 {
            let curr_dig = u_num % 16;
            u_num /= 16;

            if curr_dig > 9 {
                res.push((curr_dig - 10) as u8 + b'a');
            } else {
                res.push(curr_dig as u8 + b'0');
            }
        }

        res.reverse();

        String::from_utf8(res).unwrap()
    }
}
