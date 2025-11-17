impl Solution {
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        let mut curr_distance = k;

        for num in nums.iter() {
            if *num == 1 {
                if curr_distance < k {
                    return false;
                }

                curr_distance = 0;
            } else {
                curr_distance += 1;
            }
        }

        true
    }
}
