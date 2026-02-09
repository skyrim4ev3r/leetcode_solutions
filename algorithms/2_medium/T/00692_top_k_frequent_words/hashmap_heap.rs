use std::collections::{HashMap, BinaryHeap};

impl Solution {
    #[inline(always)]
    fn init_freqs(words: Vec<String>) -> HashMap<String, i32> {
        let mut freqs: HashMap<String, i32> = HashMap::new();
        for w in words.into_iter() {
            *freqs.entry(w).or_insert(0) += 1;
        }
        freqs
    }

    #[inline(always)]
    fn init_freqs_heap_top_k(freqs: HashMap<String, i32>, k: usize) -> BinaryHeap<(i32, String)> {
        let mut freqs_heap: BinaryHeap<(i32, String)> = BinaryHeap::with_capacity(k + 1);

        for (w, freq) in freqs.into_iter() {
            freqs_heap.push((-freq, w));

            if freqs_heap.len() > k {
                freqs_heap.pop();
            }
        }

        freqs_heap
    }

    pub fn top_k_frequent(words: Vec<String>, k: i32) -> Vec<String> {
        let freqs = Self::init_freqs(words);
        let mut freqs_heap = Self::init_freqs_heap_top_k(freqs, k as usize);
        let mut res: Vec<String> = Vec::with_capacity(k as usize);

        while let Some((_, w)) = freqs_heap.pop() {
            res.push(w);
        }

        res.reverse();

        res
    }
}
