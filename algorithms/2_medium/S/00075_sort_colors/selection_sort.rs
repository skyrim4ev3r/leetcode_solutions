impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let len = nums.len();

        for i in 0..len {
            let mut min_index = i;

            for j in (i + 1)..len {
                if nums[j] < nums[min_index] {
                    min_index = j;
                }
            }

            let tmp = nums[min_index];
            nums[min_index] = nums[i];
            nums[i] = tmp;
        }
    }
}
