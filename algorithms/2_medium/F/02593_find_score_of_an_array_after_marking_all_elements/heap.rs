use std::collections::BinaryHeap;

impl Solution {
    pub fn find_score(mut nums: Vec<i32>) -> i64 {
        let len = nums.len();
        let mut res = 0_i64;
        let mut heap: BinaryHeap<(i32, i32)> = BinaryHeap::with_capacity(nums.len());

        for (i, num) in nums.iter().enumerate() {
            heap.push((-num, -(i as i32)));
        }

        while let Some((_, negative_index)) = heap.pop() {
            let index = (-negative_index) as usize;

            if nums[index] < 0 {
                continue;
            }

            res += nums[index] as i64;
            nums[index] = -1;

            if index > 0 {
                nums[index - 1] = -1;
            }

            if index + 1 < len {
                nums[index + 1] = -1;
            }
        }

        res
    }
}
