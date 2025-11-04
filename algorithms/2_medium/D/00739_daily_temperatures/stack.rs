impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {

        let mut stack: Vec<(i32, usize)> = Vec::new();
        let len = temperatures.len();
        let mut res: Vec<i32> = vec![0_i32; len];

        for i in (0..len).rev() {
            while let Some((val, _)) = stack.last() && *val <= temperatures[i] {
                stack.pop();
            }

            if let Some((_, index)) = stack.last() {
                res[i] = (index - i) as i32;
            }

            stack.push((temperatures[i], i));
        }

        res
    }
}
