impl Solution {
    pub fn min_operations(logs: Vec<String>) -> i32 {
        let mut curr = 0_i32;

        for log in logs.into_iter() {
            match log.as_str() {
                "../" => curr = if curr == 0 { 0 } else { curr - 1 },
                "./" => {},
                _ => curr += 1,
            }
        }

        curr
    }
}
