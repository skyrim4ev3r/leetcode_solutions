impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();
        let mut res = vec![0_i32; len];

        for i in 0..len {
            let curr = nums[i] as isize;

            if curr != 0 {
                let mut steps = curr.abs() % (len as isize);

                if curr < 0 {
                    steps *= -1;
                }

                let mut target_index = i as isize + steps;

                if target_index < 0 {
                    target_index += len as isize;
                } else if target_index >= len as isize {
                    target_index -= len as isize;
                }

                res[i] = nums[target_index as usize];
            }
        }

        res
    }
}
