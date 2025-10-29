impl Solution {
    pub fn maximum_product(mut nums: Vec<i32>) -> i32 {
        let (mut max1, mut max2, mut max3) = (i32::MIN,i32::MIN,i32::MIN);
        let (mut min1, mut min2) = (i32::MAX,i32::MAX);

        for num in nums.into_iter() {
            if num < min1 {
                min2 = min1;
                min1  = num;
            } else if num < min2 {
                min2 = num;
            }

            if num > max1 {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if num > max2 {
                max3 = max2;
                max2 = num;
            } else if num > max3 {
                max3 = num;
            }
        }

        (min1 * min2 * max1).max(max3 * max2 * max1)
    }
}
