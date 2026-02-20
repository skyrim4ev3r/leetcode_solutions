// This implementation is for testing concurrency.
// Note: LeetCode will run this code as single-threaded, leading to inefficiencies.

use std::sync::Mutex;
use std::sync::atomic::{AtomicUsize, Ordering};

impl Solution {
    const MAX_INPUT: usize = 100_000;
    const SEEN_POOLS: usize = 3;

    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let len = nums.len();

        static POOL_INDEX: AtomicUsize = AtomicUsize::new(0);
        static SEEN: [Mutex<[bool; Solution::MAX_INPUT + 1]>; Solution::SEEN_POOLS] = [
            Mutex::new([false; Solution::MAX_INPUT + 1]),
            Mutex::new([false; Solution::MAX_INPUT + 1]),
            Mutex::new([false; Solution::MAX_INPUT + 1]),
        ];

        let seen_index = POOL_INDEX.fetch_add(1, Ordering::SeqCst) % Solution::SEEN_POOLS;
        let mut seen = SEEN[seen_index].lock().unwrap();
        let max_elem = nums.iter().map(|x| *x).max().unwrap();

        for i in 0..=(max_elem as usize) {
            seen[i] = false;
        }

        for i in (0..len).rev() {
            let cache = &mut seen[nums[i] as usize];
            if *cache {
                return ((i / 3) + 1) as i32;
            }
            *cache = true;
        }

        0
    }
}
