use std::collections::{HashMap,HashSet};

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let uniques: HashSet<_> = nums.into_iter().collect();
        let mut begin_to_end_interveals: HashMap<i32, i32> = HashMap::new();
        let mut end_to_begin_interveals: HashMap<i32, i32> = HashMap::new();

        for num in uniques.into_iter() {
            let mut res1 = begin_to_end_interveals.remove(&(num + 1));
            let mut res2 = end_to_begin_interveals.remove(&(num - 1));

            match (res1, res2) {
                (Some(end), Some(start)) => {
                    begin_to_end_interveals.insert(start, end);
                    end_to_begin_interveals.insert(end, start);;
                },
                (Some(end), None) => {
                    begin_to_end_interveals.insert(num, end);
                    end_to_begin_interveals.insert(end, num);;
                },
                (None, Some(start)) => {
                    begin_to_end_interveals.insert(start, num);
                    end_to_begin_interveals.insert(num, start);;
                },
                (None, None) => {
                    begin_to_end_interveals.insert(num, num);
                    end_to_begin_interveals.insert(num, num);
                }
            }
        }

        let mut max = 0_i32;

        for (start, end) in begin_to_end_interveals.into_iter() {
            max = max.max(end - start + 1);
        }

        max
    }
}
