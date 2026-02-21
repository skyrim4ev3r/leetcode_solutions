impl Solution {
    pub fn min_operations(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let len = nums1.len();
        let extra_num = *nums2.last().unwrap();
        let mut extra_num_min_cost = i32::MAX;
        let mut total_cost = 0_i64;

        for i in 0..len {
            let min = nums1[i].min(nums2[i]);
            let max = nums1[i].max(nums2[i]);
            total_cost += (max - min) as i64;

            if extra_num >= min && extra_num <= max {
                extra_num_min_cost = 0;
            } else if extra_num > max {
                extra_num_min_cost = extra_num_min_cost.min(extra_num - max);
            } else {
                extra_num_min_cost = extra_num_min_cost.min(min - extra_num);
            }
        }

        total_cost + 1 + extra_num_min_cost as i64
    }
}
