use std::collections::BTreeMap;

impl Solution {
    const MAX_SIZE: usize = 128;

    pub fn frequency_sort(s: String) -> String {        
        let mut res: Vec<u8> = Vec::with_capacity(s.len());
        let mut freqs: Vec<(i32, u8)> = (0..Self::MAX_SIZE as u8).into_iter().map(|x| (0_i32, x)).collect();

        s.into_bytes().into_iter().for_each(|byte| freqs[byte as usize].0 += 1);
        freqs.retain(|x| x.0 != 0);
        freqs.sort_unstable_by(|a, b| b.0.cmp(&a.0));

        for (count, ch) in freqs.into_iter() {
            for _ in 0..count {
                res.push(ch);
            }
        }

        String::from_utf8(res).unwrap()
    }
}
