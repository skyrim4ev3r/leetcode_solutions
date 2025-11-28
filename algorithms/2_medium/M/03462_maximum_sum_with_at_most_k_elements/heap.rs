use std::collections::BinaryHeap;

impl Solution {
    pub fn max_sum(mut grid: Vec<Vec<i32>>, limits: Vec<i32>, k: i32) -> i64 {
        if k == 0 {
            return 0;
        }

        for row in grid.iter_mut() {
            row.sort_unstable_by(|a, b| b.cmp(&a));
        }

        let mut heap: BinaryHeap<i32> = BinaryHeap::new();
        let k_usize = k as usize;

        for (i, row) in grid.iter().enumerate() {
            for j in 0..(limits[i] as usize) {
                if row[j] == 0 || (heap.len() == k_usize && row[j] <= -1 * (*heap.peek().unwrap())) {
                    break;
                }

                heap.push(-row[j]);

                if heap.len() > k_usize {
                    heap.pop();
                }
            }
        }

        -1 * heap.into_iter().map(|x| x as i64).sum::<i64>()
    }
}
