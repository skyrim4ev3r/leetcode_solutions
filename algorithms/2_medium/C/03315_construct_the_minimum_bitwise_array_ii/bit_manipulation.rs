impl Solution {
    pub fn min_bitwise_array(mut nums: Vec<i32>) -> Vec<i32> {
        for num_iter in nums.iter_mut() {
            let curr_num = *num_iter;

            if curr_num == 2 {
                *num_iter = -1; // Special case for prime number 2
            } else {
                let mut mask = 1_i32;
                // Find the lowest bit that is 0
                while (curr_num & mask) != 0 {
                    mask = mask << 1;
                }
                mask = mask >> 1; // Move back to the last bit that was 1
                *num_iter = (curr_num ^ mask); // Toggle that bit
            }
        }

        nums
    }
}
