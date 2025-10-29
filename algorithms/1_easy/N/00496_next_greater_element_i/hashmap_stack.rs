use std::collections::HashMap;

impl Solution {
    pub fn next_greater_element(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut curr_max = i32::MIN;
        let mut hashmap: HashMap<i32, i32> = HashMap::new();
        let mut stack: Vec<i32> = Vec::new();

        for num in nums2.into_iter().rev() {
            while let Some(val) = stack.last() && *val < num {
                stack.pop();
            }

            if let Some(val) = stack.last() {
                hashmap.insert(num, *val);
            } else {
                hashmap.insert(num, -1);
            }

            stack.push(num);
        }

        let mut res: Vec<i32> = Vec::with_capacity(nums1.len());
        
        for num in nums1.into_iter() {
            res.push(hashmap[&num]);
        }

        res
    }
}
