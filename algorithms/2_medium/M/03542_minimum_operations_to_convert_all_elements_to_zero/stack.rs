impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut stack: Vec<i32> = Vec::with_capacity(nums.len());
        let mut count = 0_i32;

        for num in nums.into_iter() {
            while let Some(val) = stack.last() && *val > num {
                stack.pop();
                count += 1;
            }

            if num == 0 {
                continue;
            }

            if let Some(val) = stack.last() && *val  == num {
                continue;
            }

            stack.push(num);
        }

        count + stack.len() as i32
    }
}
