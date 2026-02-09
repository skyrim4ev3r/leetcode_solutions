use std::collections::HashMap;

impl Solution {
    #[inline(always)]
    fn init_freqs(words: Vec<String>) -> HashMap<String, i32> {
        let mut freqs: HashMap<String, i32> = HashMap::new();
        for w in words.into_iter() {
            *freqs.entry(w).or_insert(0) += 1;
        }
        freqs
    }

    pub fn top_k_frequent(words: Vec<String>, k: i32) -> Vec<String> {
        let mut freqs = Self::init_freqs(words);
        let mut freqs_vec = freqs.into_iter().collect::<Vec<_>>();

        freqs_vec.sort_unstable_by(|a, b| {
            if a.1 == b.1 {
                a.0.cmp(&b.0)
            } else {
                b.1.cmp(&a.1)
            }
        });

        freqs_vec.into_iter().map(|(s, _)| s).take(k as usize).collect::<Vec<_>>()
    }
}
