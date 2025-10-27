impl Solution {
    pub fn find_smallest_integer(nums: Vec<i32>, value: i32) -> i32 {
        let value_usize = value as usize;
        let mut remainders = vec![0_i32; value_usize];

        for num in nums.into_iter() {
            let mut index = num.abs() as usize % value_usize;

            // Adjust index for negative numbers
            if index != 0 && num < 0 {
                index = value_usize - index;
            }

            remainders[index] += 1;
        }

        let mut res = 0_i32;
        let mut curr_reminder_index = 0_usize;

        while remainders[curr_reminder_index] != 0 {
            remainders[curr_reminder_index] -= 1;
            res += 1;
            curr_reminder_index += 1;

            if curr_reminder_index == value_usize {
                curr_reminder_index = 0;
            }
        }

		res
    }
}
