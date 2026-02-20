use std::collections::BinaryHeap;

impl Solution {
    pub fn maximum_score(nums: Vec<i32>, s: String) -> i64 {
        let len = nums.len();
        let bytes = s.as_bytes();
        let mut heap: BinaryHeap<i32> = BinaryHeap::new();
        let mut sum = 0_i64;

        for i in 0..len {
            heap.push(nums[i]);

            if bytes[i] == b'1' {
                sum += heap.pop().unwrap() as i64;
            }
        }

        sum
    }
}
