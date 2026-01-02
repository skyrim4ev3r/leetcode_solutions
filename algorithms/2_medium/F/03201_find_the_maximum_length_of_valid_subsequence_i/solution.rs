impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let mut odd_count = 0_i32;
        let mut even_count = 0_i32;
        let mut switch_count = 0_i32;
        let mut prev_is_even = !(nums[0] % 2 == 0);

        for num in nums.iter() {
            let curr_is_even  = (num % 2 == 0);

            if curr_is_even {
                even_count += 1;
            } else {
                odd_count += 1;
            }

            if curr_is_even !=  prev_is_even {
                prev_is_even = curr_is_even;
                switch_count += 1;
            }
        }

        switch_count.max(even_count).max(odd_count)
    }
}
