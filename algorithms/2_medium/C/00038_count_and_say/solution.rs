impl Solution {
    fn RLE(v: Vec<u8>) -> Vec<u8> {

        let len = v.len();
        let mut start = 0_usize;
        let mut end = 0_usize;
        let mut res: Vec<u8> = Vec::with_capacity(len * 2);

        while end < len {
            while end < len && v[end] == v[start] {
                end += 1;
            }
            res.extend((end - start).to_string().into_bytes());
            res.push(v[start]);
            start = end;
        }

        res
    }

    pub fn count_and_say(n: i32) -> String {
        let mut res = vec![b'1'];

        for _ in 2..=n {
            res = Self::RLE(res);
        }

        String::from_utf8(res).unwrap()
    }
}
