impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let mut max = s.len() as i32;
        let mut min = 0_i32;
        let mut res: Vec<i32> = Vec::with_capacity(s.len());

        for byte in s.as_bytes().iter() {
            if *byte == b'D' {
                res.push(max);
                max -= 1;
            } else {
                res.push(min);
                min += 1;
            }
        }

        res.push(min);

        res
    }
}
