impl Solution {
    pub fn minimum_cost(nums: Vec<i32>) -> i32 {
        let mut min1 = i32::MAX;
        let mut min2 = i32::MAX;

        for &num in nums.iter().skip(1) {
            if num < min1 {
                min2 = min1;
                min1 = num;
            } else if num < min2 {
                min2 = num;
            }
        }

        min1 + min2 + nums[0]
    }
}
