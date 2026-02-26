impl Solution {
    pub fn maximum_possible_size(nums: Vec<i32>) -> i32 {
        let mut stack: Vec<i32> = Vec::with_capacity(nums.len());

        for num in nums.into_iter().rev() {
            while let Some(top) = stack.last() && *top < num {
                stack.pop();
            }

            stack.push(num);
        }

        stack.len() as i32
    }
}
