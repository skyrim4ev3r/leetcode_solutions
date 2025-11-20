use std::collections::HashMap;

impl Solution {
    pub fn minimum_distance(nums: Vec<i32>) -> i32 {
        let mut hashmap: HashMap<i32, (isize, isize, isize)> = HashMap::new();
        let mut min_diff = -1_isize;

        for (i, num) in nums.iter().enumerate() {
            let data = hashmap.entry(*num).or_insert((-1, -1, -1));

            if data.0 == -1 {
                data.0 = i as isize;
            } else if data.1 == -1 {
                data.1 = i as isize;
            } else {
                if data.2 == -1 {
                    data.2 = i as isize;
                } else {
                    data.0 = data.1;
                    data.1 = data.2;
                    data.2 = i as isize;
                }

                let curr_diff = (data.2 - data.0) * 2;

                if min_diff == -1 || curr_diff < min_diff {
                    min_diff = curr_diff;
                }
            }
        }

        min_diff as i32
    }
}
