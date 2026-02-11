use std::collections::BinaryHeap;

impl Solution {
    #[inline(always)]
    fn reorganize_string_from_heap(heap: &mut BinaryHeap<(i32, u8)>, word_len: usize) -> String {
        let max_freq = heap.peek().unwrap().0 as usize;

        if word_len - max_freq + 1 < max_freq {
            return "".to_string();
        }

        let mut res: Vec<u8> = Vec::with_capacity(word_len);

        while let Some((freq1, byte1)) = heap.pop() {
            if let Some(prev_byte) = res.last() && *prev_byte == byte1 {
                if let Some((freq2, byte2)) = heap.pop() {
                    res.push(byte2);
                    if freq2 > 1 {
                        heap.push((freq2 - 1, byte2));
                    }
                } else {
                    unreachable!()
                }
            }
            res.push(byte1);
            if freq1 > 1 {
                heap.push((freq1 - 1, byte1));
            }
        }

        String::from_utf8(res).unwrap()
    }

    pub fn reorganize_string(s: String) -> String {
        if s.is_empty() { return "".to_string(); }
    
        let mut freqs = [0_i32; 26];
        for &byte in s.as_bytes().iter() {
            freqs[(byte - b'a') as usize] += 1;
        }

        let mut heap: BinaryHeap<(i32, u8)> = BinaryHeap::with_capacity(26);

        for (i, freq) in freqs.iter().enumerate() {
            if *freq > 0 {
                heap.push((*freq, i as u8 + b'a'));
            }
        }

        Self::reorganize_string_from_heap(&mut heap, s.len())
    }
}
