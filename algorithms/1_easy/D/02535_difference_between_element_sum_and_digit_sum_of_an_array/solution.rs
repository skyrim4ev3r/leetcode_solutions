impl Solution {
    pub fn difference_of_sum(nums: Vec<i32>) -> i32 {
        let mut nums_sum = 0;
        let mut digits_sum = 0;

        for num in nums.into_iter() {
            nums_sum += num;

            let mut tmp = num;
            while tmp > 0 {
                digits_sum += tmp % 10;
                tmp /= 10;
            }
        }

        nums_sum - digits_sum // No need for abs(), nums_sum is always greater
    }
}
