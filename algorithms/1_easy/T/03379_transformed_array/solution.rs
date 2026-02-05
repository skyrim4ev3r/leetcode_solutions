impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();
        let mut res = vec![0_i32; len];

        for i in 0..len {
            let steps = (nums[i] as isize) % (len as isize);
            let target_index = (i as isize + steps + len as isize) % len as isize;
            res[i] = nums[target_index as usize];
        }

        res
    }
}
