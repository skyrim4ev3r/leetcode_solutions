impl Solution {
    pub fn smallest_index(nums: Vec<i32>) -> i32 {
        for (index, mut val) in nums.into_iter().enumerate() {
            let mut dig_sum = 0_i32;

            while val > 0 {
                dig_sum += val % 10;
                val /= 10; 
            }

            if dig_sum == index as i32 {
                return index as i32;
            }
        }

        -1
    }
}

