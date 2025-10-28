use std::collections::HashMap;

impl Solution {
    pub fn occurrences_of_element(nums: Vec<i32>, queries: Vec<i32>, x: i32) -> Vec<i32> {

        let mut occurrences_vec: Vec<i32> = Vec::new();

        for (index, num) in nums.into_iter().enumerate() {
            if num == x {
                occurrences_vec.push(index as i32);
            }
        }

        let mut res: Vec<i32> = Vec::with_capacity(queries.len());
        let occurrences_vec_len = occurrences_vec.len();

        for query in queries.into_iter() {
            let index = query as usize - 1;

            if index >= occurrences_vec_len {
                res.push(-1);
            } else {
                res.push(occurrences_vec[index]);
            }
        }

        res
    }
}
