impl Solution {
    pub fn can_see_persons_count(heights: Vec<i32>) -> Vec<i32> {

        let len = heights.len();
        let mut res: Vec<i32> = vec![0; len];
        let mut stack: Vec::<i32> = Vec::new();

        for i in (0..len).rev() {
            while let Some(val) = stack.last() {
                res[i] += 1;

                if *val <= heights[i] {
                    stack.pop();
                } else {
                    break;
                }
            }

            stack.push(heights[i]);
        }

        res
    }
}
