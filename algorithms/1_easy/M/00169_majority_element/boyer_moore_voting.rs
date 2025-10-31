impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut majority_candidate = 0_i32;
        let mut count = 0_i32;

        for num in nums.into_iter() {
            if count == 0 {
                majority_candidate = num;
                count = 1;
            } else if majority_candidate == num {
                count += 1;
            } else {
                count -= 1;
            }
        }

        majority_candidate
    }
}
