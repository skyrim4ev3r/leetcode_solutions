impl Solution {
    pub fn create_target_array(nums: Vec<i32>, index: Vec<i32>) -> Vec<i32> {
        
        let len = nums.len();
        let mut res: Vec<i32> = Vec::new();

        for i in 0..len {
            res.insert(index[i] as usize, nums[i]);
        }

        res
    }
}
