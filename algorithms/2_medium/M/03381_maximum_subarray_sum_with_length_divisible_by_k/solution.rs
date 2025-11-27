impl Solution {
    pub fn max_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
        let k_usize = k as usize;
        let mut max = i64::MIN;
        let mut pref_sum = 0_i64;
        let mut min_pref = vec![(i64::MAX) / 2; k_usize];
        min_pref[k_usize - 1] = 0;

        for (i, num) in nums.iter().enumerate() {
            let min_pref_index = i % k_usize;

            pref_sum += (*num) as i64;
            max = max.max(pref_sum - min_pref[min_pref_index]);
            min_pref[min_pref_index] = min_pref[min_pref_index].min(pref_sum);
        }

        max
    }
}
