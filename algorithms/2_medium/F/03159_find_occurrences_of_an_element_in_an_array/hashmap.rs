use std::collections::HashMap;

impl Solution {
    pub fn occurrences_of_element(nums: Vec<i32>, queries: Vec<i32>, x: i32) -> Vec<i32> {

        let mut occurrences_map: HashMap<i32, i32> = HashMap::new();
        let nums_len = nums.len();
        let queries_len = queries.len();
        let mut count = 0_i32;

        for i in 0..nums_len {
            if nums[i] == x {
                count += 1;
                occurrences_map.insert(count, i as i32);
            }
        }

        let mut res: Vec<i32> = Vec::with_capacity(queries_len);

        for query in queries.into_iter() {
            let val: i32 = *occurrences_map.get(&query).unwrap_or(&-1);
            res.push(val);
        }

        res
    }
}
