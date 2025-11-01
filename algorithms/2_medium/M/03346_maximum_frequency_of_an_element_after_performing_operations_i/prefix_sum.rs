impl Solution {
    pub fn max_frequency(nums: Vec<i32>, k: i32, num_operations: i32) -> i32 {

        let mut max_freq = 0_i32;
        let max_val = *nums.iter().max().unwrap();
        let min_val = *nums.iter().min().unwrap();
        let counts_len = (max_val - min_val + 2) as usize;
        let mut counts = vec![0_i32; counts_len];

        for &num in nums.iter() {
            counts[(num - min_val + 1) as usize] += 1;
        }

        for i in 1..counts_len {
            counts[i] += counts[i - 1];
        }

        for i in 1..counts_len {
            let curr = i as i32 ;

            let left = (curr - k).max(1) as usize;
            let right = (curr + k).min(max_val - min_val + 1) as usize;

            let total = counts[right] - counts[left - 1];
            let total_free_cost = counts[i] - counts[i - 1];
            let total_with_cost = total - total_free_cost;

            let curr_freq = total_free_cost + total_with_cost.min(num_operations);

            max_freq = max_freq.max(curr_freq);
        }

        max_freq
    }
}
