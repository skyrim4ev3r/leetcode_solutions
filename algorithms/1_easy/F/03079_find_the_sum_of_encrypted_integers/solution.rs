impl Solution {
    pub fn sum_of_encrypted_int(nums: Vec<i32>) -> i32 {
        let mut final_res = 0_i32;

        for mut num in nums.into_iter() {
            let mut dig_count = 0_i32;
            let mut max_dig = 0_i32;

            while num > 0 {
                let curr_dig = num % 10;
                num /= 10;

                max_dig = max_dig.max(curr_dig);
                dig_count += 1;
            }

            let mut curr_res = 0_i32;
            for i in 0..dig_count {
                curr_res *= 10;
                curr_res += max_dig;
            }

            final_res += curr_res;
        }

        final_res
    }
}
