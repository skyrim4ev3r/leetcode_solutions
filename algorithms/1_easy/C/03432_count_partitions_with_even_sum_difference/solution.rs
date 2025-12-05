impl Solution {
    pub fn count_partitions(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut r_sum = nums.iter().map(|x| *x).sum::<i32>();
        let mut l_sum = 0_i32;
        let mut count = 0_i32;

        for i in 0..(len - 1) {
            l_sum += nums[i];
            r_sum -= nums[i];

            if (r_sum - l_sum) % 2 == 0 {
                count += 1;
            }
        }

        count
    }
}
