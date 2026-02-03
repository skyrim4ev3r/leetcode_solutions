impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let mut seen = {
            let max_num = nums.iter().map(|x| *x).max().unwrap();
            vec![false; (max_num + 1) as usize]
        };

        let mut max_sum = 0_i32;
        let mut curr_sum = 0_i32;
        let mut left = 0_usize;
        let len = nums.len();

        for right in 0..len {
            let num = nums[right];
            let num_index = nums[right] as usize;

            while seen[num_index] {
                seen[nums[left] as usize] = false;
                curr_sum -= nums[left];
                left += 1;
            }

            curr_sum += num;
            seen[num_index] = true;
            max_sum = max_sum.max(curr_sum);
        }

        max_sum
    }
}
