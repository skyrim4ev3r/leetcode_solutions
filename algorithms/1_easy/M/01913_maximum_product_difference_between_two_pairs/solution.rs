impl Solution {
    pub fn max_product_difference(nums: Vec<i32>) -> i32 {

        let mut min1 = i32::MAX;
        let mut min2 = i32::MAX;
        let mut max1 = i32::MIN;
        let mut max2 = i32::MIN;

        for num in nums.into_iter() {
            if num < min2 {
                min1 = min2;
                min2 = num;
            } else if num < min1 {
                min1 = num;
            }

            if max2 < num {
                max1 = max2;
                max2 = num;
            } else if max1 < num {
                max1 = num;
            }
        }

        (max1 * max2) - (min1 * min2)
    }
}
