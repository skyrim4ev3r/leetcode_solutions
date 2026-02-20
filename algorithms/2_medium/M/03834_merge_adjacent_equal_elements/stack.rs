impl Solution {
    pub fn merge_adjacent(nums: Vec<i32>) -> Vec<i64> {
        let mut stack: Vec<i64> = Vec::new();

        for num in nums.into_iter() {
            let mut temp = num as i64;

            while let Some(val) = stack.last() && *val == temp {
                temp *= 2;
                stack.pop();
            }

            stack.push(temp);
        }

        stack
    }
}
