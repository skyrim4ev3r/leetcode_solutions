use std::collections::BinaryHeap;

impl Solution {
    pub fn total_cost(costs: Vec<i32>, k: i32, candidates: i32) -> i64 {

        let len = costs.len();
        let candidates_usize = candidates as usize;

        let mut left_heap: BinaryHeap<i32> = BinaryHeap::new();
        let mut right_heap: BinaryHeap<i32> = BinaryHeap::new();

        let mut left_index = 0_usize;
        let mut right_index = len - 1;
        let mut res = 0_i64;

        for _ in 0..k {
            while left_index <= right_index && left_heap.len() < candidates_usize {
                left_heap.push(-costs[left_index]);
                left_index += 1;
            }

            while left_index <= right_index && right_heap.len() < candidates_usize {
                right_heap.push(-costs[right_index]);
                right_index -= 1;
            }

            let cost_left = left_heap.peek().unwrap_or(&i32::MAX).abs();
            let cost_right = right_heap.peek().unwrap_or(&i32::MAX).abs();

            if cost_left <= cost_right {
                res += cost_left as i64;
                left_heap.pop();
            } else {
                res += cost_right as i64;
                right_heap.pop();
            }
        }

        res
    }
}
