use std::collections::HashMap;

impl Solution {
    pub fn find_x_sum(nums: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
        let k_usize = k as usize;
        let x_usize = x as usize;
        let len = nums.len();
        let mut freqs: HashMap<i32, i32> = HashMap::new();
        let mut res: Vec<i32> = Vec::new();
        let mut left = 0_usize;

        for i in 0..k_usize {
            *freqs.entry(nums[i]).or_insert(0) += 1;
        }

        #[inline]
        fn calculate_x_sum(freqs: &HashMap<i32, i32>, x: &usize) -> i32 {
            let mut freqs_vec: Vec<(i32, i32)> = freqs.iter().map(|(&k, &v)| (k, v)).collect();
            freqs_vec.sort_by(|(k1, v1), (k2, v2)| if v1 == v2 { k2.cmp(&k1) } else { v2.cmp(&v1) });
            freqs_vec.iter().take(*x).map(|&(k, v)| k * v).sum()
        }

        res.push(calculate_x_sum(&freqs, &x_usize));

        for right in k_usize..len {
            *freqs.entry(nums[right]).or_insert(0) += 1;

            let left_elem = nums[left];
            if let Some(counter) = freqs.get_mut(&left_elem) {
                *counter -= 1;
                if *counter == 0 {
                    freqs.remove(&left_elem);
                }
            }
            left += 1;

            res.push(calculate_x_sum(&freqs, &x_usize));
        }

        res
    }
}
