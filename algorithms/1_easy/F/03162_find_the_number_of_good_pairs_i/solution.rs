impl Solution {
    pub fn number_of_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> i32 {
        let mut count = 0;

        for num1 in nums1.into_iter() {
            for &num2 in nums2.iter() {
                if num1 % (k * num2) == 0 {
                    count += 1;
                }
            }
        }

        count
    }
}
