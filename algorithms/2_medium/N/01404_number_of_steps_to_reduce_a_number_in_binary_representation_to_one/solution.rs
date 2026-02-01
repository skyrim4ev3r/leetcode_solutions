impl Solution {
    pub fn num_steps(s: String) -> i32 {
        let mut count = 0_i32;
        let mut bytes = s.into_bytes();

        while bytes.len() > 1 && *bytes.last().unwrap() == b'0' {
            count += 1;
            bytes.pop();
        }

        if bytes.len() == 1 {
            return count;
        }

        count + (bytes.len() as i32) + 1 + bytes.into_iter().filter(|x| *x == b'0').count() as i32
    }
}
