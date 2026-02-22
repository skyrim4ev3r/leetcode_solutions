impl Solution {
    pub fn can_sort_array(nums: Vec<i32>) -> bool {
        let mut curr_max = i32::MIN;
        let mut prev_max = i32::MIN;

        for num in nums.into_iter() {
            if curr_max.count_ones() != num.count_ones() {
                prev_max = curr_max;
                curr_max = num;
            } else {
                curr_max = curr_max.max(num);
            }

            if num < prev_max {
                return false;
            }
        }

        true
    }
}
