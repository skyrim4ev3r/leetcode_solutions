impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let nums_xor = nums.iter().map(|x| *x).fold(0_i32, |res, num| res ^ num);
        //least_bit_one INT_MIN is INT_MIN,  
        let least_bit_one = if nums_xor == i32::MIN {nums_xor} else {nums_xor & (-nums_xor)};
        let mut num1 = 0_i32;
        let mut num2 = 0_i32;

        for num in nums.iter() {
            if (least_bit_one & *num) == 0 {
                num1 ^= *num;
            } else {
                num2 ^= *num;
            }
        }

        vec![num1, num2]
    }
}
