impl Solution {
    pub fn majority_element(mut nums: Vec<i32>) -> i32 {

        nums.sort_unstable();

        let len = nums.len();
        let half = (len as i32) / 2;
        let mut count = 1_i32;

        for i in 1..len {
            if nums[i-1] == nums[i] {
                count += 1;
            } else {
                count = 1;
            }

            if count > half {
                return nums[i];
            }
        }

        nums[0]
    }
}
