impl Solution {
    pub fn build_array(target: Vec<i32>, n: i32) -> Vec<String> {
        let target_len = target.len();
        let mut target_index = 0_usize;
        let mut num = 1_i32;
        let mut res: Vec<String> = Vec::new();

        while target_index <  target_len{
            res.push("Push".to_string());

            if num == target[target_index] {
                target_index += 1;
            } else {
                res.push("Pop".to_string());
            }

            num += 1;
        }

        res
    }
}
