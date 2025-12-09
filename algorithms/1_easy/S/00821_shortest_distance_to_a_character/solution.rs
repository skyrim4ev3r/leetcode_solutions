impl Solution {
    pub fn shortest_to_char(s: String, c: char) -> Vec<i32> {
        let len = s.len();
        let mut res = vec![i32::MAX; len];
        let mut last_pos = -1_i32;
        let byte_c = c as u8;

        for (i, byte) in s.as_bytes().iter().enumerate() {
            if *byte == byte_c {
                last_pos = i as i32;
            }

            if last_pos != -1 {
                res[i] = i as  i32 - last_pos;
            }
        }

        last_pos = -1;
        for (i, byte) in s.as_bytes().iter().rev().enumerate() {
            if *byte == byte_c {
                last_pos = i as i32;
            }

            if last_pos != -1 {
                res[len - 1 - i] = res[len - 1 - i].min(i as i32 - last_pos);
            }
        }

        res
    }
}
