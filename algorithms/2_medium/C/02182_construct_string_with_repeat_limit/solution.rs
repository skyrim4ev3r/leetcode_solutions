impl Solution {
    pub fn repeat_limited_string(s: String, repeat_limit: i32) -> String {
        let mut res: Vec<u8> = Vec::with_capacity(s.len());
        let mut freqs = [0_i32; 26];

        for byte in s.as_bytes().iter() {
            freqs[(*byte - b'a') as usize] += 1;
        }

        let mut stack: Vec<(u8, i32)> = Vec::with_capacity(26);

        for i in 0..26 {
            if freqs[i] > 0 {
                stack.push((i as u8 + b'a', freqs[i]));
            }
        }

        while let Some((byte, mut freq)) = stack.pop() {
            while freq != 0 {
                let curr_repeat = repeat_limit.min(freq);
                freq -= curr_repeat;

                for i in 0..curr_repeat {
                    res.push(byte);
                }

                if freq > 0 {
                    if let Some(pair) = stack.last_mut() {
                        res.push(pair.0);
                        pair.1 -= 1;

                        if pair.1 == 0 {
                            stack.pop();
                        }
                    } else {
                        return String::from_utf8(res).unwrap();
                    }
                }
            }
        }

        String::from_utf8(res).unwrap()
    }
}
