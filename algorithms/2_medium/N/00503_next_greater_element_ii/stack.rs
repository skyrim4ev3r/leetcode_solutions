impl Solution {
    pub fn next_greater_elements(nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();
        let mut max_index = 0;

        for i in 0..len {
            if nums[i] > nums[max_index] {
                max_index = i;
            }
        }

        let mut res = vec![0_i32; len];
        res[max_index] = -1;
        let mut index = if max_index == 0 {len - 1} else {max_index - 1};
        let mut stack: Vec<i32> = vec![nums[max_index]];

        while index != max_index {
            let curr_num = nums[index];

            while let Some(val) = stack.last() && *val <= curr_num {
                stack.pop();
            }

            if let Some(val) = stack.last() {
                res[index] = *val;
            } else {
                res[index] = -1;
            }

            if index == 0 {
                index = len - 1;
            } else {
                index -= 1;
            }

            stack.push(curr_num);
        }

        res
    }
}
