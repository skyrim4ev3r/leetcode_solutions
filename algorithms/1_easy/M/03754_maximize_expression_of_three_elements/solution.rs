impl Solution {
    pub fn maximize_expression_of_three(nums: Vec<i32>) -> i32 {
        let mut max1 = i32::MIN;
        let mut max2 = i32::MIN;
        let mut min1 = i32::MAX;

        for num in nums.iter() {
            if *num > max1 {
                max2 = max1;
                max1 = *num;
            } else {
                max2 = max2.max(*num);
            }

            min1 = min1.min(*num);
        }

        max1 + max2 - min1
    }
}
