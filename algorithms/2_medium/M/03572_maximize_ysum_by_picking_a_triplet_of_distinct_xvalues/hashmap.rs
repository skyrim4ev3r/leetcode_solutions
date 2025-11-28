use std::collections::HashMap;

impl Solution {
    pub fn max_sum_distinct_triplet(x: Vec<i32>, y: Vec<i32>) -> i32 {
        let mut hashmap: HashMap<i32, i32> = HashMap::new();

        for (i, val) in x.into_iter().enumerate() {
            let other = hashmap.entry(val).or_insert(0);
            *other = (*other).max(y[i]);
        }

        let (mut max1, mut max2, mut max3) = (-1_i32, -1_i32, -1_i32);

        for (_, val) in hashmap.into_iter() {
            if val > max1 {
                max3 = max2;
                max2 = max1;
                max1 = val;
            } else if val > max2 {
                max3 = max2;
                max2 = val;
            } else if val > max3 {
                max3 = val;
            }
        }

        if max3 == -1 {
            return -1;
        }

        max1 + max2 + max3
    }
}
