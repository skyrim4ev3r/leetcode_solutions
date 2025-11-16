use std::collections::BinaryHeap;

impl Solution {
    pub fn last_stone_weight(stones: Vec<i32>) -> i32 {
        let mut heap: BinaryHeap<i32> = stones.iter().map(|x| *x).collect::<BinaryHeap<i32>>();

         while heap.len() > 1 {
            let x = heap.pop().unwrap();
            let y = heap.pop().unwrap();

            if x != y {
                heap.push(x - y);
            }
        }

        if heap.is_empty() {0_i32} else {heap.pop().unwrap()}
    }
}
