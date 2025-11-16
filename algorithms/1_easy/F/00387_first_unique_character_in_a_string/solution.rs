impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut freqs = [(0_i32, 0_usize); 26];
        let len = s.len();

        for (i, byte) in s.as_bytes().iter().enumerate() {
            let char_as_index = (*byte - b'a') as usize;

            if freqs[char_as_index].0 == 0 {
                freqs[char_as_index].0 = 1;
                freqs[char_as_index].1 = i;
            } else {
                freqs[char_as_index].0 = 2;
            }
        }

        let mut res = len;

        for (count, index) in freqs.iter() {
            if *count == 1 {
                res = res.min(*index);
            }
        }

        if res == len {
           return  -1;
        }

        res as i32
    }
}
