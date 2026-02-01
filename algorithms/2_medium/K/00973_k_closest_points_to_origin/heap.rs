use std::collections::BinaryHeap;

impl Solution {
    pub fn k_closest(points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let k_usize = k as usize;
        let mut heap: BinaryHeap<(i32, Vec<i32>)> = BinaryHeap::with_capacity(k_usize + 1);

        for p in points.into_iter() {
            let val = p[0] * p[0] + p[1] * p[1];
            heap.push((val, p));

            if heap.len() > k_usize {
                heap.pop();
            }
        }

        heap.into_iter().map(|(_, v)| v).collect::<Vec<_>>()
    }
}
