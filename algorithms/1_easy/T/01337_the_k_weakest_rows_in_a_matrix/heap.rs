use std::collections::BinaryHeap;

impl Solution {
    pub fn k_weakest_rows(mat: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let mut heap: BinaryHeap<(usize, usize)> = BinaryHeap::new();
        let k_usize = k as usize;

        for (index, row) in mat.iter().enumerate() {
            let count = row.iter().filter(|x| **x == 1).count();

            if heap.len() < k_usize {
                heap.push((count, index));
            } else {
                if let Some(d) = heap.peek() && d.0 > count {
                    heap.push((count, index));
                    heap.pop();
                }
            }
        }

        let len = heap.len();
        let mut res = vec![0_i32; len];

        for i in (0..len).rev() {
            res[i] = heap.pop().unwrap().1 as i32;
        }

        res
    }
}
