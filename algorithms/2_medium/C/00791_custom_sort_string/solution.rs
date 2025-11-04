/*
        O(m + n)        nested loop wont add complexity
*/
impl Solution {
    pub fn custom_sort_string(order: String, s: String) -> String {
        const freqs_len: usize = 26_usize;
        let mut freqs = [0_i32; freqs_len];
        let mut res: Vec<u8> = Vec::with_capacity(s.len());

        s.into_bytes().into_iter().for_each(|ch| freqs[(ch - b'a') as usize] += 1);

        for ch in order.into_bytes().into_iter() {
            let freq_index = (ch - b'a') as usize;
            let freq = freqs[freq_index];
            freqs[freq_index] = 0;

            for _ in 0..freq {
                res.push(ch);
            }
        }

        for i in 0..freqs_len {
            if freqs[i] > 0 {
                let ch = i as u8 + b'a';

                for _ in 0..freqs[i] {
                    res.push(ch);
                }
            }
        }

        String::from_utf8(res).unwrap()
    }
}
