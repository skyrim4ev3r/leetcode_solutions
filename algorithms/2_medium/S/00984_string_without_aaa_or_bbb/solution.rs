impl Solution {
    pub fn str_without3a3b(mut a: i32, mut b: i32) -> String {
        let mut res: Vec<u8> = Vec::with_capacity((a + b) as usize);

        while a > 0 || b > 0 {
            let len = res.len();

            if len >= 2 && res[len - 1] == res[len - 2] {
                if res[len - 1] == b'a' {
                    res.push(b'b');
                    b -= 1;
                } else {
                    res.push(b'a');
                    a -= 1;
                }
            } else if a >= b {
                res.push(b'a');
                a -= 1;
            } else {
                res.push(b'b');
                b -= 1;
            }
        }

        String::from_utf8(res).unwrap()
    }
}
