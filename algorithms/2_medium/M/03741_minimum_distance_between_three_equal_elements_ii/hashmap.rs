use std::collections::HashMap;

impl Solution {
    pub fn minimum_distance(nums: Vec<i32>) -> i32 {
        let mut min = -1_i32;
        let mut datas: HashMap<i32, (i32, i32, i32)> = HashMap::new();

        for (i, num) in nums.into_iter().enumerate() {
            let num_data = datas.entry(num).or_insert((-1, -1, -1));

            if num_data.0 == -1 {
                num_data.0 = i as i32;
            } else if num_data.1 == -1 {
                num_data.1 = i as i32;
            } else {
                if num_data.2 == -1 {
                    num_data.2 = i as i32;
                } else {
                    num_data.0 = num_data.1;
                    num_data.1 = num_data.2;
                    num_data.2 = i as i32;
                }

                let curr_distance = (num_data.2 - num_data.0) * 2;

                if min == -1 || min > curr_distance {
                    min = curr_distance;
                }
            }
        }

        min
    }
}
