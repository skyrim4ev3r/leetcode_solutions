impl Solution {
    pub fn convert_to_title(mut col_number: i32) -> String {
        let mut res: Vec<u8> = Vec::new();

        while col_number >= 1 {
            let rem = (col_number - 1) % 26;
            res.push(rem as u8 + b'A');
            col_number = (col_number - 1) / 26;
        }

        res.reverse();

        String::from_utf8(res).unwrap()
    }
}
