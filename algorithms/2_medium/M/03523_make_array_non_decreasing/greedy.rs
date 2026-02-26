impl Solution {
    pub fn maximum_possible_size(nums: Vec<i32>) -> i32 {
        let total_count = nums.len() as i32;
        let mut curr_max = i32::MIN;
        let mut remove_count = 0_i32;

        for num in nums.into_iter() {
            curr_max = curr_max.max(num);

            if num < curr_max {
                remove_count += 1;
            }
        }

        total_count - remove_count
    }
}
