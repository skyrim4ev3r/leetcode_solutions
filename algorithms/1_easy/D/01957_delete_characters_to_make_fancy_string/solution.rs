impl Solution {
    pub fn make_fancy_string(s: String) -> String {

        let mut repeats = 0_i32;
        let mut prev_char = 0_u8;
        let mut res: Vec<u8> = Vec::new();;

        for byte in s.as_bytes().iter() {
            if *byte == prev_char {
                repeats += 1;
            } else {
                prev_char = *byte;
                repeats = 1;
            }

            if repeats <= 2 {
                res.push(*byte);
            }
        }

        String::from_utf8(res).unwrap()
    }
}
